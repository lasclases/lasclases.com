#!/usr/bin/env python3
import sys
import re
import os
import glob
from pathlib import Path

def convert_file(filepath, verbose=True, backup=True, dry_run=False):
    """
    Convierte un archivo HTML de Windows-1252 a UTF-8
    y actualiza el tag meta charset.
    """
    path = Path(filepath)
    
    if not path.exists():
        print(f"❌ Error: El archivo '{filepath}' no existe.")
        return False
    
    if not path.is_file():
        print(f"❌ Error: '{filepath}' no es un archivo regular.")
        return False
    
    try:
        # Leer original en CP1252
        if verbose:
            print(f"📄 Leyendo '{filepath}' (CP1252)...")
        
        content = path.read_text(encoding='cp1252')
        
        # Hacer backup (antes de cualquier modificación)
        if backup and not dry_run:
            backup_path = path.with_suffix(path.suffix + '.backup')
            if verbose:
                print(f"💾 Creando backup '{backup_path}'...")
            path.rename(backup_path)
            # Re-leer del backup para procesar
            content = backup_path.read_text(encoding='cp1252')
        
        # Reemplazar tag meta charset (case-insensitive)
        # Captura: <meta charset="windows-1252"> o <meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
        pattern = r'<meta\s+(?:charset\s*=\s*["\'](?:windows-1252|cp1252)["\']|http-equiv\s*=\s*["\']content-type["\']\s+content\s*=\s*["\']text/html;\s*charset\s*=\s*(?:windows-1252|cp1252)["\'])\s*(/?)>'
        replacement = r'<meta charset="utf-8"\1>'
        
        new_content = re.sub(pattern, replacement, content, flags=re.IGNORECASE)
        num_replacements = len(re.findall(pattern, content, flags=re.IGNORECASE))
        
        if dry_run:
            if verbose:
                print(f"🔍 [DRY-RUN] Encontrado(s) {num_replacements} tag(s) meta.")
                print(f"   Se reemplazarían {len(content)} caracteres CP1252 a UTF-8.")
            return True
        
        # Escribir en UTF-8
        if verbose:
            print(f"✍️  Escribiendo '{filepath}' (UTF-8)...")
        
        path.write_text(new_content, encoding='utf-8')
        
        if verbose:
            status = f"({num_replacements} tag(s) meta)" if num_replacements > 0 else "(sin tags meta)"
            print(f"✅ Convertido '{filepath}' {status}.")
        
        return True
        
    except Exception as e:
        print(f"❌ Error procesando '{filepath}': {e}")
        return False

def main():
    if len(sys.argv) < 2:
        print("""Uso: python script.py archivo.html [archivo2.html ...]
Ejemplos:
  python script.py index.html
  python script.py *.html
  python script.py --dry-run *.html  (para probar sin modificar)
  python script.py --no-backup *.html (para no crear backups)

Opciones:
  --dry-run    Simula el proceso sin modificar archivos
  --no-backup  No crea archivos .backup (NO RECOMENDADO)
""")
        sys.exit(1)
    
    # Parsear argumentos
    args = sys.argv[1:]
    dry_run = '--dry-run' in args
    backup = '--no-backup' not in args
    
    # Filtrar opciones para obtener solo archivos
    files = [arg for arg in args if not arg.startswith('--')]

    # Expandir wildcards
    expanded_files = []
    for f in files:
        if '*' in f or '?' in f:
            expanded_files.extend(glob.glob(f))
        else:
            expanded_files.append(f)

    if not expanded_files:
        print("❌ Error: No se especificaron archivos.")
        sys.exit(1)

    print(f"🚀 Procesando {len(expanded_files)} archivo(s)...\n")

    success = fail = 0
    for filepath in expanded_files:
        if convert_file(filepath, verbose=True, backup=backup, dry_run=dry_run):
            success += 1
        else:
            fail += 1
    
    # Resumen
    print(f"\n📊 Resumen: {success} ok, {fail} errores.")

    if success > 0 and not dry_run and backup:
        print("\n💡 Los archivos originales se guardaron con extensión '.backup'")
        print("   Verifica todo antes de eliminarlos.")

if __name__ == "__main__":
    main()