ejercicio 3 

def media(vector):
    suma = 0
    
    for numero in vector:
        suma += numero
    
    return suma / len(vector)


def varianza(vector):
    prom = media(vector)
    suma = 0
    
    for numero in vector:
        suma += (numero - prom) ** 2
    
    return suma / len(vector)


# Ejemplo de uso
muestra = [10, 20, 30, 40, 50]

print("Media:", media(muestra))
print("Varianza:", varianza(muestra))


  ejercicio 4

  import math

def media(vector):
    suma = 0
    
    for valor in vector:
        suma += valor
    
    return suma / len(vector)


def pearson_r(VA, VB):
    promedio_a = media(VA)
    promedio_b = media(VB)

    suma_num = 0
    suma_a = 0
    suma_b = 0

    for i in range(len(VA)):
        diferencia_a = VA[i] - promedio_a
        diferencia_b = VB[i] - promedio_b

        suma_num += diferencia_a * diferencia_b
        suma_a += diferencia_a ** 2
        suma_b += diferencia_b ** 2

    denominador = math.sqrt(suma_a * suma_b)

    return suma_num / denominador


# Ejemplo de uso
VA = [1, 2, 3, 4, 5]
VB = [2, 4, 6, 8, 10]

print("Coeficiente de Pearson:", pearson_r(VA, VB))


  ejercicio 5

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Convierte un caracter hexadecimal a entero
int char_to_val(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

// Convierte un entero a caracter hexadecimal
char val_to_char(int v) {
    if (v < 10)
        return '0' + v;
    return 'A' + (v - 10);
}

// Convierte de cualquier base a decimal
int base_to_dec(vector<char> s, int base) {
    int resultado = 0;

    for (char c : s) {
        resultado = resultado * base + char_to_val(c);
    }

    return resultado;
}

// Convierte de decimal a cualquier base
vector<char> dec_to_base(int n, int base) {
    if (n == 0)
        return {'0'};

    vector<char> resultado;

    while (n > 0) {
        int residuo = n % base;
        resultado.push_back(val_to_char(residuo));
        n /= base;
    }

    reverse(resultado.begin(), resultado.end());

    return resultado;
}


// ==========================
// DECIMAL A OTRAS BASES
// ==========================

vector<char> dec_to_septapus(int n) {
    return dec_to_base(n, 7);
}

vector<char> dec_to_octopus(int n) {
    return dec_to_base(n, 8);
}

vector<char> dec_to_hexakaidecapus(int n) {
    return dec_to_base(n, 16);
}


// ==========================
// OTRAS BASES A DECIMAL
// ==========================

vector<char> septapus_to_dec(vector<char> s) {
    int valor = base_to_dec(s, 7);
    return dec_to_base(valor, 10);
}

vector<char> octopus_to_dec(vector<char> s) {
    int valor = base_to_dec(s, 8);
    return dec_to_base(valor, 10);
}

vector<char> hexakaidecapus_to_dec(vector<char> s) {
    int valor = base_to_dec(s, 16);
    return dec_to_base(valor, 10);
}


// ==========================
// CONVERSIONES ENTRE ESPECIES
// ==========================

vector<char> septapus_to_octopus(vector<char> s) {
    int valor = base_to_dec(s, 7);
    return dec_to_base(valor, 8);
}

vector<char> septapus_to_hexakaidecapus(vector<char> s) {
    int valor = base_to_dec(s, 7);
    return dec_to_base(valor, 16);
}

vector<char> octapus_to_septapus(vector<char> s) {
    int valor = base_to_dec(s, 8);
    return dec_to_base(valor, 7);
}

vector<char> octopus_to_hexakaidecapus(vector<char> s) {
    int valor = base_to_dec(s, 8);
    return dec_to_base(valor, 16);
}

vector<char> hexakaidecapus_to_septapus(vector<char> s) {
    int valor = base_to_dec(s, 16);
    return dec_to_base(valor, 7);
}

vector<char> hexakaidecapus_to_octopus(vector<char> s) {
    int valor = base_to_dec(s, 16);
    return dec_to_base(valor, 8);
}


// ==========================
// FUNCION AUXILIAR PARA IMPRIMIR
// ==========================

void imprimir(vector<char> v) {
    for (char c : v)
        cout << c;

    cout << endl;
}


// ==========================
// EJEMPLO DE USO
// ==========================

int main() {

    vector<char> numero_hex = {'1', 'A', '8'};

    cout << "Hexakaidecapus a decimal: ";
    imprimir(hexakaidecapus_to_dec(numero_hex));

    cout << "Hexakaidecapus a Septapus: ";
    imprimir(hexakaidecapus_to_septapus(numero_hex));

    cout << "Hexakaidecapus a Octopus: ";
    imprimir(hexakaidecapus_to_octopus(numero_hex));

    return 0;
}
