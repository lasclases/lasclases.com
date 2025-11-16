#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import ftfy
from pathlib import Path

def arreglar_codificacion_html(directorio_raiz):
    """
    Recorre recursivamente todos los archivos HTML y arregla problemas de codificación UTF-8 mal interpretados
    """
    # Contadores para el reporte
    total_archivos = 0
    archivos_modificados = 0
    archivos_con_errores = 0
    
    # Extensiones de archivo a procesar
    extensiones_validas = {'.html', '.htm'}
    
    print(f"🔍 Buscando archivos HTML en: {directorio_raiz}")
    
    # Recorrer recursivamente todos los archivos
    for ruta_archivo in Path(directorio_raiz).rglob('*'):
        if ruta_archivo.suffix.lower() in extensiones_validas:
            total_archivos += 1
            
            try:
                # Leer el archivo
                with open(ruta_archivo, 'r', encoding='utf-8', errors='ignore') as archivo:
                    contenido = archivo.read()
                
                # Arreglar la codificación con ftfy
                contenido_arreglado = ftfy.fix_text(contenido)
                
                # Verificar si hubo cambios
                if contenido != contenido_arreglado:
                    archivos_modificados += 1
                    print(f"✏️  Arreglando: {ruta_archivo}")
                    
                    # Guardar el archivo arreglado
                    with open(ruta_archivo, 'w', encoding='utf-8') as archivo:
                        archivo.write(contenido_arreglado)
                
            except Exception as e:
                archivos_con_errores += 1
                print(f"❌ Error procesando {ruta_archivo}: {e}")
    
    # Reporte final
    print(f"\n📊 Resumen:")
    print(f"   Total de archivos HTML encontrados: {total_archivos}")
    print(f"   Archivos modificados: {archivos_modificados}")
    print(f"   Archivos con errores: {archivos_con_errores}")
    
    return total_archivos, archivos_modificados, archivos_con_errores

def arreglar_manualmente(contenido):
    """
    Método alternativo manual si ftfy no está disponible
    """
    reemplazos = {
        'Ã¡': 'á', 'Ã©': 'é', 'Ã­': 'í', 'Ã³': 'ó', 'Ãº': 'ú',
        'Ã': 'Á', 'Ã‰': 'É', 'Ã': 'Í', 'Ã“': 'Ó', 'Ãš': 'Ú',
        'Ã±': 'ñ', 'Ã‘': 'Ñ',
        'Ã€': 'À', 'Ãˆ': 'È', 'ÃŒ': 'Ì', 'Ã’': 'Ò', 'Ã™': 'Ù',
        'Ã ': 'à', 'Ã¨': 'è', 'Ã¬': 'ì', 'Ã²': 'ò', 'Ã¹': 'ù',
        'Ã¤': 'ä', 'Ã«': 'ë', 'Ã¯': 'ï', 'Ã¶': 'ö', 'Ã¼': 'ü',
        'Ã„': 'Ä', 'Ã‹': 'Ë', 'Ã': 'Ï', 'Ã–': 'Ö', 'Ãœ': 'Ü',
        'Ã¿': 'ÿ', 'Å': '¿', 'Â¡': '¡', 'Â¿': '¿'
    }
    
    for mal, bien in reemplazos.items():
        contenido = contenido.replace(mal, bien)
    
    return contenido

if __name__ == "__main__":
    import sys
    
    # Directorio por defecto (carpeta actual)
    directorio = "."
    
    # Si se pasa un argumento, usar ese directorio
    if len(sys.argv) > 1:
        directorio = sys.argv[1]
    
    # Verificar si existe el directorio
    if not os.path.exists(directorio):
        print(f"❌ Error: El directorio '{directorio}' no existe")
        sys.exit(1)
    
    print("🚀 Iniciando arreglo de codificación en archivos HTML...")
    
    try:
        # Intentar usar ftfy (recomendado)
        import ftfy
        print("✅ Usando librería ftfy para arreglo automático")
        arreglar_codificacion_html(directorio)
        
    except ImportError:
        print("⚠️  La librería 'ftfy' no está instalada")
        print("📥 Instálala con: pip install ftfy")
        print("🔄 Se usará el método manual de reemplazo")
        
        # Método manual alternativo
        for ruta_archivo in Path(directorio).rglob('*.html'):
            try:
                with open(ruta_archivo, 'r', encoding='utf-8', errors='ignore') as archivo:
                    contenido = archivo.read()
                
                contenido_arreglado = arreglar_manualmente(contenido)
                
                if contenido != contenido_arreglado:
                    print(f"✏️  Arreglando manualmente: {ruta_archivo}")
                    with open(ruta_archivo, 'w', encoding='utf-8') as archivo:
                        archivo.write(contenido_arreglado)
                        
            except Exception as e:
                print(f"❌ Error procesando {ruta_archivo}: {e}")