#include <iostream>
#include <string>
using namespace std;

struct GLLNode {
    bool isAtom;      
    string atom;          
    GLLNode* sublist;      
    GLLNode* next;         
};

GLLNode* createAtom(string val) {
    GLLNode* node = new GLLNode;
    node->isAtom = true;
    node->atom = val;
    node->sublist = nullptr;
    node->next = nullptr;
    return node;
}

GLLNode* createSublist(GLLNode* list) {
    GLLNode* node = new GLLNode;
    node->isAtom = false;
    node->sublist = list;
    node->next = nullptr;
    return node;
}

void displayGLL(GLLNode* head) {
    cout << "{";
    GLLNode* temp = head;
    while (temp) {
        if (temp->isAtom) {
            cout << temp->atom;
        } else {
            displayGLL(temp->sublist); 
        }
        if (temp->next) cout << ", ";
        temp = temp->next;
    }
    cout << "}";
}

int main() {

    GLLNode* inner1 = createSublist(nullptr); 
    GLLNode* uvList = createAtom("u");
    uvList->next = createAtom("v");
    GLLNode* inner2 = createSublist(uvList);

    GLLNode* yzList = createAtom("y");
    yzList->next = createAtom("z");
    GLLNode* sublistMain = createAtom("r");
    sublistMain->next = createAtom("s");
    sublistMain->next->next = createAtom("t");
    sublistMain->next->next->next = inner1;       
    sublistMain->next->next->next->next = inner2; 
    sublistMain->next->next->next->next->next = createAtom("w");
    sublistMain->next->next->next->next->next->next = createAtom("x");
    sublistMain->next->next->next->next->next->next->next = createSublist(yzList);
    sublistMain->next->next->next->next->next->next->next->next = createAtom("a1");
    sublistMain->next->next->next->next->next->next->next->next->next = createAtom("b1");

    GLLNode* S = createAtom("p");
    S->next = createAtom("q");
    S->next->next = createSublist(sublistMain);

    cout << "Set S = ";
    displayGLL(S);
    cout << endl;

    return 0;
}
