#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <class T>
class linkedList {
    private:
        class StCourse {
            public:

                string subName , grad;
                T total , point;
                StCourse* Cnext;
        };
        class node {
            string name, department;
            int numRegCourses;
            StCourse* st;
            node* next;

            friend class linkedList;
            friend class Iterator;
        };

        node *head = NULL, *tail = NULL;

    public:
        linedList(){
            head = NULL;
            tail = NULL;
        }
        class Iterator {
            protected:
                node* currNode;
            public:

            Iterator() : currNode(NULL) {

            }

            Iterator(node* n) : currNode(n) {

            }

            Iterator& operator =(node* n) {
                this->currNode = n;
                return *this;
            }

            Iterator& operator++() {
                if (currNode)
                    currNode = currNode->next;
                return *this;
            }

            Iterator operator++(int) {
                Iterator it = *this;
                ++*this;
                return it;
            }

            bool operator!=(const Iterator& it) {
                return currNode != it.currNode;
            }

            int operator*() {
                return currNode->numRegCourses;
            }
        };
        Iterator begin(){
            return Iterator(head);
        }
        Iterator end(){
            return Iterator(NULL);
        }
        void push_backNode(string Name, string Dep, int num){
            node* n = new node;
            n->name = Name;
            n->department = Dep;
            n->numRegCourses = num;
            n->next = NULL;

            if(head == NULL) {
                head = n;
                tail = n;
                head->st = NULL;
                n = NULL;
            }else {
                tail->next = n;
                tail->next->st = NULL;
                tail = n;
            }
            cout << "Here u will Enter " << Name << "'s data------\n";
            for(int i = 1; i <= num; ++i){
                string s , g;
                T t , p;
                StCourse* cour = new StCourse;
                cout << "Please Enter " << i << " subject data!\n";
                cout << "Enter subject name: ";
                cin >> s;
                cour->subName = s;
                cout << "Enter subject's total : ";
                cin >> t;
                cour->total = t;
                cout << "Enter subject's grade: ";
                cin >> g;
                cour->grad = g;
                cout << "Enter subject's point: ";
                cin >> p;
                cour->point = p;
                cour->Cnext = NULL;
                if (tail->st == NULL) {
                    tail->st = cour;
                }else {
                    struct StCourse* nn = tail->st;
                    while (nn->Cnext != NULL)
                        nn = nn->Cnext;
                    nn->Cnext = cour;
                }
            }
        }

        void print(){
            node* temp = new node;
            temp = head;
            while(temp != NULL){
                cout << temp->name << " ";
                cout << temp->department << " ";
                cout << temp->numRegCourses << "\n";

                struct StCourse *CurrentCourse = temp->st;
                int i = 1;
                while(CurrentCourse != NULL){
                    cout << i << " Subject name: " << CurrentCourse->subName << "\n";
                    cout << "Total: " << CurrentCourse->total << "\n";
                    cout << "Grade: " << CurrentCourse->grad << "\n";
                    cout << "Point: " << CurrentCourse->point << "\n";
                    cout << "-----------------------------------------------------\n";
                    CurrentCourse = CurrentCourse->Cnext;
                    i++;
                }

                temp = temp->next;
                cout << "-----------------------------------------------------\n";
            }
        }
};

int main()
{
    linkedList<double> lst;
    linkedList<double>::Iterator it;

    lst.push_backNode("mostafa" , "CS" , 1);
    lst.push_backNode("mazen" , "CS" , 1);
    lst.push_backNode("Eslam" , "IT" , 2);

    lst.print();

    cout << "\n";

    for(it = lst.begin(); it != lst.end(); ++it)
        cout << *it << "\n";

    return 0;
}
