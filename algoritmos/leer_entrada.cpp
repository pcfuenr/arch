#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>

std::vector<int> lecturaEntrada(){
    namespace fs = std::filesystem;
    std::vector<int> numeros;
    int numero;

    // rutas posibles a dataset
    fs::path ds = "../../dataset";
    if (!fs::exists(ds) || !fs::is_directory(ds)) {
        // quizá ejecutas desde la raíz del repo
        ds = fs::path("arch") / "dataset";
    }
    if (!fs::exists(ds) || !fs::is_directory(ds)) {
        std::cerr << "ERROR: no pude localizar la carpeta 'dataset' ni en '../dataset' ni en 'arch/dataset'\n"
                  << "CWD = " << fs::current_path() << "\n";
        std::exit(EXIT_FAILURE);
    }

    // 1) Listar binarios
    std::vector<std::string> archivos;
    for (auto& e : fs::directory_iterator(ds)) {
        if (e.is_regular_file() && e.path().extension()==".bin")
            archivos.push_back(e.path().filename().string());
    }
    if (archivos.empty()) {
        std::cerr << "ERROR: no hay .bin en " << ds << "\n";
        std::exit(EXIT_FAILURE);
    }
    std::sort(archivos.begin(), archivos.end());

    // 2) Mostrar menú
    //std::cout << "Archivos en " << ds << ":\n";
    //for (size_t i = 0; i < archivos.size(); ++i)
    //    std::cout << "  " << (i+1) << ". " << archivos[i] << "\n";

    // 3) Leer opción
    size_t op = 0;
    while (op<1 || op>archivos.size()) {
    //    std::cout << "Selecciona (1-" << archivos.size() << "): ";
        std::cin >> op;
    }

    // 4) Abrir y leer
    fs::path file = ds / archivos[op-1];
    std::ifstream in(file, std::ios::binary);
    if (!in) { std::cerr<<"no pude abrir "<<file<<"\n"; std::exit(EXIT_FAILURE); }
    while (in.read(reinterpret_cast<char*>(&numero), sizeof(int)))
        numeros.push_back(numero);

    std::cout << numeros.size() << ";" << archivos[op-1];
    return numeros;
}