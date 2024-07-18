#include <iostream>
#include <vector>
#include <algorithm>

class Object {
public:
    Object(int dist) : distance(dist) {}

    int distanza() const {
        return distance;
    }

private:
    int distance;
};

// Definizione del funtore per confrontare gli oggetti in base alla distanza
class CompareObjects {
public:
    bool operator()(const Object& a, const Object& b) const {
        return a.distanza() < b.distanza();
    }
};

int main() {
    // Definisci il vettore di oggetti
    std::vector<Object> vettore = {Object(5), Object(2), Object(8), Object(3)};

    // Ordina il vettore in base alla distanza crescente
    std::sort(vettore.begin(), vettore.end(), CompareObjects());

    // Stampare il vettore ordinato
    for (const auto& obj : vettore) {
        std::cout << obj.distanza() << " ";
    }
    std::cout << std::endl;

    return 0;
}
