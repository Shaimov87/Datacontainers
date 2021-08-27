#include<iostream>

using namespace std;

class Element {
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNexp = nullptr) :Data(Data), pNext(pNext) {
		cout << "\tEconstructor\t" << this << endl;
	}

	~Element() {
		cout << "\tEDestructor\t" << this << endl;
	}
	int get_data() {
		return Data;
	}
	friend class ForwardList;
};
class ForwardList {
	Element* Head;
public:
	ForwardList() {
		Head = nullptr;
		cout << "\tLconstructor\t" << this << endl;
	}
	~ForwardList()
	{
		Element* Temp = Head;

		while (Head != nullptr) {
			Temp = Head->pNext;
			delete Head;
			cout << "\tLDestructor\t" << Head << endl;
			Head = Temp;
		}
		delete Temp;

	}
	void push_front(int Data) {
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}
	void push_back(int Data) {
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr) {
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
	}
	void pop_front() {
		Element* Temp = Head;
		Head = Temp->pNext;
		delete Temp;
	}
	void pop_back() {
		Element* Last = Head;
		while (Last->pNext != nullptr) {
			Last = Last->pNext;
		}
		Element* Temp = Head;
		while (Temp->pNext != Last) {
			Temp = Temp->pNext;
		}
		Temp->pNext = nullptr;
		delete Last;
	}
	ForwardList& operator=(const ForwardList& other) {
		Element* Temp = other.Head;
		while (Temp->pNext != nullptr) {
			Element* New = new Element(Temp->Data);
			Temp = Temp->pNext;
			New->pNext = Head;
			Head = New;
		}

		return *this;
	}
	void print()const
	{

		Element* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};
int main() {
	int n;
	cout << "\tplease enter";
	cin >> n;

	ForwardList list;
	for (int i = 0; i < n; i++) {
		list.push_front(rand() % 100);
	}
	list.print();

	list.push_back(76);
	list.print();

	list.pop_front();
	list.print();

	list.pop_back();
	list.print();

	ForwardList list1;
	list1 = list;
	list1.print();

	return 0;
}