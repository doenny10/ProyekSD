#include<iostream>
#include<string>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<algorithm>
#include<cctype>
using namespace std;

class node {
private:
	int data;
	node *next, *front, *rear;
public:
	node() {
		next = NULL;
		front = NULL;
		rear = NULL;
	}

	int GetData() {
		return data;
	}

	void SetData(int x) {
		data = x;
	}

	node * GetNext() {
		return (next);
	}

	void SetNext(node* nextnode) {
		next = nextnode;
	}
};

//CLASS STACK LINKED LIST
class StackusingList {
private:
	node *top;
	int count; //head
	int maxnum;
	int stackData;
public:
	StackusingList(int max = 0)
	{
		top = NULL;
		maxnum = max;
		count = 0;
	}

	void setmax(int x) {
		maxnum = x;
	}

	void push(int element) {
		if (count == maxnum)
			cout << "stack is full";
		else
		{
			node *newTop = new node;
			if (top == NULL) {
				newTop->SetData(element);
				newTop->SetNext(NULL);
				top = newTop;
				count++;
			}
			else {
				newTop->SetData(element);
				newTop->SetNext(top);
				top = newTop;
				count++;
			}
		}
	}
	int pop() {
		if (top == NULL)
			cout << "Empty" << endl;
		else
		{
			node * old = top;
			top = top->GetNext();
			count--;
			return old->GetData();
		}
	}

	void clear() {
		while (top) {
			pop();
		}
	}

	void print() {
		node *temp;
		temp = top;
		while (temp != NULL) {

			cout << GetJenis(temp->GetData()) << endl;
			temp = temp->GetNext();
		}
		cout << endl;
	}

	string GetJenis(int n) {
		if (n == 0) {
			return  "Roti Bawah";
		}
		else if (n == 1) {
			return "Daging";
		}
		else if (n == 2) {
			return "Ham";
		}
		else if (n == 3) {
			return "Telur";
		}
		else if (n == 4) {
			return "Acar";
		}
		else if (n == 5) {
			return "Tomat";
		}
		else if (n == 6) {
			return "Paprika";
		}
		else if (n == 7) {
			return "Bawang";
		}
		else if (n == 8) {
			return "Keju";
		}
		else if (n == 9) {
			return "Roti Atas";
		}
	}
};

//NODE USING STACK
class nodes {
private:
	StackusingList *data;
	nodes *next, *front, *rear;
public:
	nodes() {
		next = NULL;
		front = NULL;
		rear = NULL;
	}

	StackusingList *GetStack() {
		return data;
	}

	void SetStack(StackusingList *x) {
		data = x;
	}

	nodes * GetNexts() {
		return (next);
	}

	void SetNexts(nodes* nextnode) {
		next = nextnode;
	}
};

//QueueSLL USING SLLSTACK
class QueueSLL {
private:
	nodes *front, *rear;
public:
	QueueSLL() { front = rear = NULL; }

	void insert(StackusingList *n) {
		nodes *temp = new nodes;
		if (temp == NULL) {
			cout << "Overflow" << endl;
			return;
		}
		temp->SetStack(n);
		temp->SetNexts(NULL);

		//for first node
		if (front == NULL) {
			front = rear = temp;
		}
		else {
			rear->SetNexts(temp);
			rear = temp;
		}

	}

	void deleteitem()
	{
		if (front == NULL) {
			cout << "underflow" << endl;
			return;
		}
		front->GetStack();
		cout << "is being deleted " << endl;
		if (front == rear)//if only one node is there
			front = rear = NULL;
		else
			front = front->GetNexts();
	}

	void display(int n)
	{
		if (front == NULL) {
			cout << "Underflow." << endl;
			return;
		}

		nodes *temp = front;
		//will check until NULL is not found				
		for (int s = 0; s < n; s++) {
			temp = temp->GetNexts();
		}
		temp->GetStack()->print();
		cout << endl;
	}

	void displayall() {

		if (front == NULL) {
			cout << "Underflow." << endl;
			return;
		}

		nodes *temp = front;
		//will check until NULL is not found				
		while (temp) {
			temp->GetStack()->print();
			temp = temp->GetNexts();
		}

		cout << endl;
	}

	~QueueSLL()
	{
		while (front != NULL)
		{
			nodes *temp = new nodes;
			temp = front;
			front = front->GetNexts();
			delete temp;
		}
		rear = NULL;
	}

	nodes *getfront() {
		return front;
	}

	StackusingList *getstack(int x) {
		if (front == NULL) {
			cout << "Underflow." << endl;
			return NULL;
		}

		nodes *temp = front;
		//will check until NULL is not found				
		for (int s = 0; s < x; s++) {
			temp = temp->GetNexts();
		}
		return temp->GetStack();
	}

};

//void transfer(QueueSLL &a, QueueSLL &b){ 
//	nodes *temp = a.getfront();
//	while (temp){
//		b.insert(temp->GetStack());
//		temp = temp->GetNexts();
//	}
//
//}


StackusingList *RandomStack(StackusingList *stack, int n) {
	stack = new StackusingList(n);
	int isi = rand() % 9 + 1;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			stack->push(0);
		}
		else if (i == n - 1) {
			stack->push(9);
		}
		else {
			isi = rand() % 8 + 1;
			stack->push(isi);
		}
	}
	return stack;
}

StackusingList kbh(int n, int x, QueueSLL &z, int timer = 0) {
	int rotibawah = 0, telur = 0, keju = 0, ham = 0, tomat = 0, bawang = 0, paprika = 0, acar = 0, daging = 0, rotiatas = 0;
	StackusingList *a = new StackusingList(x);
	char ch;
	int count = 0;

	timer = timer * 10;
	while (timer >= 0 && count != x)
	{
		system("CLS");
		cout << timer / 10 << endl;
		z.display(n);
		cout << endl;
		cout << "0. Roti Bawah = " << rotibawah << endl;
		cout << "1. Daging = " << daging << endl;
		cout << "2. Ham = " << ham << endl;
		cout << "3. Telur = " << telur << endl;
		cout << "4. Acar = " << acar << endl;
		cout << "5. Tomat = " << tomat << endl;
		cout << "6. Paprika = " << paprika << endl;
		cout << "7. Bawang = " << bawang << endl;
		cout << "8. Keju = " << keju << endl;
		cout << "9. Roti Atas = " << rotiatas << endl;
		cout << "Clear : Space\n";

		if (kbhit())
		{
			ch = getch();
			if (ch == 32) { //space
				a->clear();
				rotibawah = 0;
				telur = 0;
				keju = 0;
				ham = 0;
				tomat = 0;
				bawang = 0;
				paprika = 0;
				acar = 0;
				daging = 0;
				rotiatas = 0;
				count = 0;
			}
			else {
				if (ch == 48) {//0
					rotibawah++;
					a->push(0);
				}
				else if (ch == 49) {//1
					daging++;
					a->push(1);
				}
				else if (ch == 50) {//2
					ham++;
					a->push(2);
				}
				else if (ch == 51) {//3
					telur++;
					a->push(3);
				}
				else if (ch == 52) {//4
					acar++;
					a->push(4);
				}
				else if (ch == 53) {//5
					tomat++;
					a->push(5);
				}
				else if (ch == 54) {//6
					paprika++;
					a->push(6);
				}
				else if (ch == 55) {//7
					bawang++;
					a->push(7);
				}
				else if (ch == 56) {//8
					keju++;
					a->push(8);
				}
				else if (ch == 57) {//9
					rotiatas++;
					a->push(9);
				}
				count++;
			}
		}
		Sleep(60);
		timer--;
	}
	return *a;
}

bool cekstack(StackusingList *stack1, StackusingList *stack2, int size) {
	int isi1 = 0;
	int isi2 = 0;

	for (int a = 0; a < size; a++) {
		isi1 = stack1->pop();
		isi2 = stack2->pop();

		if (isi1 != isi2) {
			return false;
		}
	}
	return true;
}

int game(int n, int a, bool inp = false, StackusingList *input = NULL )
{
	int poin = a;
	int antri = 0;
	QueueSLL x;
	QueueSLL temp;
	StackusingList *s = new StackusingList(); // resep
	StackusingList *j = new StackusingList(); // inputan  user

											  // level 1 ( 4 resep -> 5 tumpukan/resep)
	if (n == 1) {
		if (inp) {
			x.insert(input);
			for (int i = 0; i < 3; i++)
			{
				x.insert(s = RandomStack(s, 5));
			}

		}
		else {
			for (int i = 0; i < 4; i++)
			{
				x.insert(s = RandomStack(s, 5)); // random semua resep
			}
		}

		for (int i = 0; i < 4; i++)
		{
			x.display(i); // menampilkan per resep
			cout << "Jawaban : \n";
			*j = kbh(i, 5, x, 60); // (stack ke berapa/resep, tumpukan, , waktu)
			j->print(); //
			if (cekstack(j, x.getstack(i), 5))
			{
				poin += 10;
				cout << "Poin : " << poin << endl;
				getch();
				system("CLS");
			}
			else
			{
				poin -= 10;
				cout << "Oops!!\nwrong input\nPoin : " << poin << endl;
				getch();
				system("CLS");
			}
		}
	}

	// level 2 ( 5 resep -> 6 tumpukan/resep)
	else if (n == 2) {
		for (int i = 0; i < 5; i++)
		{
			x.insert(s = RandomStack(s, 6));
		}

		for (int i = 0; i < 5; i++)
		{
			x.display(i);
			cout << "Jawaban : \n";
			*j = kbh(i, 6, x, 50);
			j->print();
			if (cekstack(j, x.getstack(i), 6))
				poin += 15;
			else
			{
				poin -= 10;
				cout << "Oops!!\nwrong input\n";
			}
			cout << "Poin : " << poin << endl;
			getch();
			system("CLS");
		}
	}

	// level 3 ( 6 resep -> 7 tumpukan/resep)
	else if (n == 3) {
		for (int i = 0; i < 6; i++)
		{
			x.insert(s = RandomStack(s, 7));
		}

		for (int i = 0; i < 6; i++)
		{
			x.display(i);
			cout << "Jawaban : \n";
			*j = kbh(i, 7, x, 40);
			j->print();
			if (cekstack(j, x.getstack(i), 7))
				poin += 20;
			else
			{
				poin -= 15;
				cout << "Oops!!\nwrong input\n";
			}
			cout << "Poin : " << poin << endl;
			getch();
			system("CLS");
		}
	}

	//level 4 ( 7 resep -> 8 tumpukan/resep)
	else if (n == 4) {
		for (int i = 0; i < 7; i++)
		{
			x.insert(s = RandomStack(s, 8));
		}

		for (int i = 0; i < 7; i++)
		{
			x.display(i);
			cout << "Jawaban : \n";
			*j = kbh(i, 8, x, 30);
			j->print();
			if (cekstack(j, x.getstack(i), 8))
				poin += 25;
			else
			{
				poin -= 15;
				cout << "Oops!!\nwrong input\n";
			}
			cout << "Poin : " << poin << endl;
			getch();
			system("CLS");
		}
	}

	return poin;
}
StackusingList *pelanggan() {
	StackusingList *a = new StackusingList(5);
	int rotibawah = 0, telur = 0, keju = 0, ham = 0, tomat = 0, bawang = 0, paprika = 0, acar = 0, daging = 0, rotiatas = 0;
	
	char ch;
	int count = 0;

	while (count != 5)
	{
		system("CLS");
		cout << "Input Burger Pelanggan sebanyak 5 Bahan";
		cout << endl;
		cout << "0. Roti Bawah = " << rotibawah << endl;
		cout << "1. Daging = " << daging << endl;
		cout << "2. Ham = " << ham << endl;
		cout << "3. Telur = " << telur << endl;
		cout << "4. Acar = " << acar << endl;
		cout << "5. Tomat = " << tomat << endl;
		cout << "6. Paprika = " << paprika << endl;
		cout << "7. Bawang = " << bawang << endl;
		cout << "8. Keju = " << keju << endl;
		cout << "9. Roti Atas = " << rotiatas << endl;
		cout << "Clear : Space\n";
		cout << endl;
		/*a->print();*/

		if (kbhit())
		{
			ch = getch();
			if (ch == 32) {//space
				a->clear();
				rotibawah = 0;
				telur = 0;
				keju = 0;
				ham = 0;
				tomat = 0;
				bawang = 0;
				paprika = 0;
				acar = 0;
				daging = 0;
				rotiatas = 0;
				count = 0;
			}
			else {
				if (ch == 48) {//0
					rotibawah++;
					a->push(0);
				}
				else if (ch == 49) {//1
					daging++;
					a->push(1);
				}
				else if (ch == 50) {//2
					ham++;
					a->push(2);
				}
				else if (ch == 51) {//3
					telur++;
					a->push(3);
				}
				else if (ch == 52) {//4
					acar++;
					a->push(4);
				}
				else if (ch == 53) {//5
					tomat++;
					a->push(5);
				}
				else if (ch == 54) {//6
					paprika++;
					a->push(6);
				}
				else if (ch == 55) {//7
					bawang++;
					a->push(7);
				}
				else if (ch == 56) {//8
					keju++;
					a->push(8);
				}
				else if (ch == 57) {//9
					rotiatas++;
					a->push(9);
				}
				count++;
			}
		}
		Sleep(60);
	
	}
	return a;

}

void main() {
	bool input = false;
	srand(time(0));
	StackusingList *inputan;
	int poin = 0;
	string display = "Y";
	bool lvl1 = false;
	bool lvl2 = false;
	bool lvl3 = false;
	bool lvl4 = false;

	while (true) {

		cout << "Welcome to Structure Burger Game !!!\n\n";
		cout << "..:: MENU ::..\n";
		cout << "1. Start(Y) \n2. Exit(N)\nChoose: ";
		fflush(stdin);
		cin >> display;

		fflush(stdin);
		system("CLS");

		char lvl = 0;
		while (display == "Y" || display == "y") {

			cout << "..:: LEVEL SELECTION ::..\n\n";
			cout << "1. LEVEL 1 \n2. LEVEL 2 \n3. LEVEL 3 \n4. LEVEL 4 \n5. BACK \n6. Input Pelanggan \n\nLEVEL: ";
			fflush(stdin);
			cin >> lvl;
			fflush(stdin);
			system("CLS");

			//LEVEL 1
			if (lvl == '1') {
				cout << "LEVEL 1\n";
				lvl1 = true;
				cout << "Ready ?\n";
				Sleep(900);
				cout << "Set\n";
				Sleep(900);
				cout << "Go !\n";
				Sleep(900);
				system("CLS");
				if(input == false){
					cout<<"Belum ada Input dari Pelanggan Pertama\n";
					cout<<"Input pesanan dari pelanggan terlebih dahulu :\n"; //Jika user lupa input pelanggan
					getch();
					inputan = pelanggan();
				}
				else if(input == true){
					poin = game(1, poin, input, inputan);
				}
				getch();
				system("CLS");
				input = false;
			}
			

			//LEVEL 2
			else if (lvl == '2') {
				if (poin >= 30) {
					cout << "LEVEL 2\n";
					lvl2 = true;
					cout << "Ready ?\n";
					Sleep(900);
					cout << "Set\n";
					Sleep(900);
					cout << "Go !\n";
					Sleep(900);
					system("CLS");
					poin = game(2, poin);
					getch();
					system("CLS");
				}
				else
					cout << "level 2 is Locked\nyour point is not enough to unlock level 2\nplease get some point from level 1";
				getch();
				system("CLS");

			}

			//LEVEL 3
			else if (lvl == '3') {
				if (poin >= 70) {
					cout << "LEVEL 3\n";
					lvl3 = true;
					cout << "Ready ?\n";
					Sleep(900);
					cout << "Set\n";
					Sleep(900);
					cout << "Go !\n";
					Sleep(900);
					system("CLS");
					poin = game(3, poin);
					getch();
					system("CLS");
				}
				else
					cout << "level 3 is Locked\nyour point is not enough to unlock level 3\nplease get some point from level 1 or level 2\n";
				getch();
				system("CLS");

			}

			//LEVEL 4
			else if (lvl == '4') {
				if (poin >= 120) {
					cout << "LEVEL 4\n";
					lvl4 = true;
					cout << "Ready ?\n";
					Sleep(900);
					cout << "Set\n";
					Sleep(900);
					cout << "Go !\n";
					Sleep(900);
					system("CLS");
					poin = game(4, poin);
					getch();
					system("CLS");
				}
				else
					cout << "level 4 is Locked\nyour point is not enough to unlock level 4\nplease get some point from level 1 or level 2 or level 3\n";
				getch();
				system("CLS");

			}
			else if (lvl == '6') {
				input = true;
				cout << "Input Burger Pelanggan sebanyak 5 Bahan\n";
				inputan = pelanggan();
				/*system("CLS");*/
				inputan->print();
				getch();
				system("CLS");
				
			}

			else if (lvl == '5') {
				if (lvl4) {
					cout << "Congratulation for Finsihing the Game\nThank you for your support to us :) \n";
					getch();
					system("CLS");
					break;
				}
				break;
			}

			else {
				cout << "INVALID LEVEL SELECTION \nPLEASE INPUT 1 / 2 / 3 / 4 / 5\n";
				getch();
				system("cls");
			}
		}

		if (display == "N" || display == "n") {
			cout << "Thanks For Playing ...\n";
			break;
		}
		else if (display != "Y" && display != "N") {
			cout << "INVALID MENU SELECTION \nPLEASE INPUT Y / N\n";
			getch();
			system("CLS");
		}

	}

}