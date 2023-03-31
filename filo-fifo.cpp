#include <iostream>
#include <tuple>
/*односвязные списки - указатель только на следующий элемент
 * двусвязные - указательно на предыдущий и на следующий элемент
 *
 *
 * 6-е задание
 * struct Node{
 *  Node* next;
 *  Node* prev;
 *  static int  countNodes;
 * }
 * static - хранит количество элементов в массиве
 * int Node::countNodes = 0;
 *
*/
struct Node{
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};
class LinkedList{
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList();
    ~LinkedList();
    void push_back(int el){
        if(Tail == nullptr){
            Tail = new Node();
            Head = new Node();
            Tail = Head;
            Head->prev = nullptr;
            Head->next = Tail;
            Tail ->prev = Head;
            Tail->next = nullptr;
            Tail->nameNode = el;
            return;
        }
        Tail->next = new Node();
        Node* temp = Tail->next;
        Tail->nameNode = el;
        temp->prev = Tail;
        temp->next = nullptr;
        Tail = temp;
    }
};
class StudentInfo {
private:
    std::tuple<std::string, std::string, char *> lalala;

public:
    StudentInfo(const std::string &, const std::string &, const char *){
    std::make_tuple<std::string, std::string, char *>("slkh", "skcah", "caj");
    }

};
int main(){
    LinkedList().push_back(10);
}