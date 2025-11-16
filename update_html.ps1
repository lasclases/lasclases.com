# PowerShell script to update HTML files with navigation and footer

$nav = @'
    <nav class="content-nav">
        <a href="../index.html">Inicio</a>
        <a href="#content">Contenido</a>
    </nav>

    <main id="content">
'@

$footer = @'
    </main>

    <footer class="site-footer">
        <p><strong>Tony Rodriguez</strong></p>
        <p><strong>Email:</strong> <a href="mailto:tony@lasclases.com">tony@lasclases.com</a></p>
    </footer>
'@

# Get all .html files recursively, excluding index.html
Get-ChildItem -Path . -Recurse -Filter "*.html" | Where-Object { $_.Name -ne "index.html" } | ForEach-Object {
    $file = $_.FullName
    $content = Get-Content $file -Raw

    # Add lang="es" to html tag if not present
    if ($content -notmatch '<html lang="es"') {
        $content = $content -replace '<html>', '<html lang="es">'
    }

    # Add viewport meta if not present
    if ($content -notmatch 'viewport') {
        $content = $content -replace '<meta charset="utf-8">', "<meta charset=`"utf-8`">`n`t<meta name=`"viewport`" content=`"width=device-width, initial-scale=1.0`">"
    }

    # Add nav after <body>
    if ($content -notmatch '<nav class="content-nav"') {
        $content = $content -replace '<body>', "<body>`n$nav"
    }

    # Add footer before </body>
    if ($content -notmatch '<footer class="site-footer"') {
        $content = $content -replace '</body>', "$footer`n</body>"
    }

    # Save the file
    Set-Content $file $content -Encoding UTF8
}