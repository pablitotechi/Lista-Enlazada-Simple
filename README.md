# 🧪 Lista Enlazada Simple en C++

**Autor:** Pablo Garro  
**Carné:** 2022150932  
**Curso:** Estructuras de Datos  

---

## 📄 Descripción

Este programa implementa una **lista enlazada simple** en C++, permitiendo la inserción, búsqueda, eliminación e impresión de elementos. También se puede insertar un elemento antes o después de una posición específica dentro de la lista.

Se utiliza un menú interactivo por consola para que el usuario manipule la lista de manera dinámica.

---

## 🏗️ Funcionalidades

| Opción | Descripción                          |
|--------|--------------------------------------|
| 1      | Insertar al inicio                   |
| 2      | Insertar al final                    |
| 3      | Insertar en una posición             |
| 4      | Imprimir lista                       |
| 5      | Buscar un valor                      |
| 6      | Eliminar un valor                    |
| 7      | Salir del programa                   |

---

## 🧱 Estructura del Código

### 🔹 `struct nodo`

Estructura que representa un nodo de la lista enlazada:

```cpp
struct nodo {
    int dato;
    nodo* siguiente;
};
