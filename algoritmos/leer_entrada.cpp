#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>

std::vector<int> lecturaEntrada(int dataset) {
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

    // 3) Abrir y leer
    fs::path file = ds / archivos[dataset-1];
    std::ifstream in(file, std::ios::binary);
    if (!in) { std::cerr<<"no pude abrir "<<file<<"\n"; std::exit(EXIT_FAILURE); }
    while (in.read(reinterpret_cast<char*>(&numero), sizeof(int)))
        numeros.push_back(numero);
    in.close();
    return numeros;
}