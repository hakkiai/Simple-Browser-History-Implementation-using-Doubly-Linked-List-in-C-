#include <iostream>
#include <string>

using namespace std;


struct Node {
    string page;
    Node* prev;
    Node* next;
};

class BrowserHistory {
private:
    Node* head;
    Node* current;

public:
    BrowserHistory() {
        head = nullptr;
        current = nullptr;
    }


    void visit(string page) {
        Node* new_node = new Node();
        new_node->page = page;
        new_node->prev = current;
        new_node->next = nullptr;

        if (current) {
            current->next = new_node;
        }
        current = new_node;
        head = new_node;
    }


    void back() {
        if (current && current->prev) {
            current = current->prev;
        }
    }

 
    void forward() {
        if (current && current->next) {
            current = current->next;
        }
    }


    string getCurrentPage() {
        return current->page;
    }

    // Destructor to free memory
    ~BrowserHistory() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    BrowserHistory browser;
    browser.visit("Google.com");
    browser.visit("facebook.com");
    browser.visit("Flipkart.com");
    cout << "Current page: " << browser.getCurrentPage() << endl; 
    browser.back();
    cout << "Current page: " << browser.getCurrentPage() << endl;  
    browser.back();
    cout << "Current page: " << browser.getCurrentPage() << endl;  
    browser.back();
    return 0;
}

