@echo off

:: Sobrescribir resultados.csv con la cabecera
echo numElementos;dataset;algoritmo;tiempo > resultados.csv

:: Definir rangos de datasets y algoritmos
set datasets=1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
set algoritmos=1 2 3 4 5 6

:: Repetir el experimento 20 veces
for /l %%i in (1,1,20) do (
    echo Iniciando iteracion %%i de 20 a las %time%
    for %%d in (%datasets%) do (
        for %%a in (%algoritmos%) do (
            echo Ejecutando: main.exe %%d %%a
            main.exe %%d %%a > temp_output.txt 2> temp_error.txt
            if errorlevel 1 (
                echo Error: Fallo al ejecutar main.exe %%d %%a en iteracion %%i >> error.log
                type temp_error.txt >> error.log
            ) else (
                type temp_output.txt >> resultados.csv
                echo Exito: Resultados agregados para dataset %%d, algoritmo %%a
            )
            del temp_output.txt temp_error.txt
        )
    )
)

echo Experimentos completados a las %time%. Revisa resultados.csv y error.log
pause