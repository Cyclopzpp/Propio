#include <iostream>

using namespace std;
typedef int tElem;

struct tNodo {

    tElem info;
    tNodo* izq;
    tNodo* der;

    tNodo(tElem val) : info(val), izq(nullptr), der(nullptr) {}

};

class tABB {

public:
    tNodo* root;
    int nElem;

    tABB();
    ~tABB();
    void clear();
    void insert(tElem item);
    void remove(tElem item);
    void postorder();
    void show();

private:
    void clearhelp(tNodo* nodo);
    void inserthelp(tNodo* nodo, tNodo* item);
    void postorhelp(tNodo* nodo);
    void printTree(tNodo* node, string prefix, bool isLeft);

};


tABB::tABB(){

    root = nullptr ;
    nElem = 0 ;

} ;

void tABB::clearhelp(tNodo* nodo){

    if (nodo == nullptr) return ;
    clearhelp(nodo -> izq) ;
    clearhelp(nodo -> der) ;
    delete nodo ;

} ;

void tABB::clear(){

    clearhelp(root) ;
    root = nullptr ;
    nElem = 0 ;

} ;

tABB::~tABB(){

    clear() ;

} ;

void tABB::inserthelp(tNodo* nodo, tNodo* item) {

    if (item->info < nodo->info) {

        if (nodo->izq != nullptr) {

            inserthelp(nodo->izq, item);

        } else {

            nodo->izq = item;
            return;

        } ;

    } else if (item->info > nodo->info) {

        if (nodo->der != nullptr) {

            inserthelp(nodo->der, item);

        } else {

            nodo->der = item;
            return;

        } ;
    } ;

} ;

void tABB::insert(tElem item) {

    tNodo* newItem = new tNodo(item);

    if (root == nullptr) {

        root = newItem;
        nElem = 1;

    } else {

        inserthelp(root, newItem);
        nElem++;

    } ;

} ;

void procesar(tElem info){

    cout << info << endl ;

} ;

void tABB::postorhelp(tNodo* nodo){

    if(nodo == nullptr) return ;
    postorhelp(nodo -> izq) ;
    postorhelp(nodo -> der) ;
    procesar(nodo -> info) ;

} ;

void tABB::postorder(){

    postorhelp(root) ;

} ;

void tABB::show() {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    printTree(root, "", true);
}

void tABB::printTree(tNodo* node, string prefix, bool isLeft) {
    if (node == nullptr) {
        return;
    }

    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << node->info << endl;

    // Recursively print the left and right subtrees
    printTree(node->izq, prefix + (isLeft ? "│   " : "    "), true);
    printTree(node->der, prefix + (isLeft ? "│   " : "    "), false);
}


int main() {
    tABB Arbol;

    Arbol.insert(70);
    Arbol.insert(45);
    Arbol.insert(93);
    Arbol.insert(22);
    Arbol.insert(40);
    Arbol.insert(69);
    Arbol.insert(30);
    Arbol.insert(99);
    Arbol.insert(95);


    cout << "Mostrando Arbol" << endl;
    Arbol.show();

    cout << "\nMostrando postorder:" << endl;
    Arbol.postorder();
}
