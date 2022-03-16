#include <iostream>
using namespace std;

//deklarasi circular single link list
struct Buku{
	string judul, pengarang, tempat_terbit;
	
	Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *after;

//create single linked list
void createCircularSingleLinkedList(string dataBaru[3]){
	head = new Buku();
	head->judul = dataBaru[0];
	head->pengarang = dataBaru[1];
	head->tempat_terbit = dataBaru[2];
	tail = head;
	tail->next = head;
}
//insert first circular single linked list
void insertFirst(string data[3]){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
	newNode = new Buku();
	newNode->judul = data[0];
	newNode->pengarang = data[1];
	newNode->tempat_terbit = data[2];
	newNode->next = head;
	tail->next = newNode;
	head = newNode;
	}
}

//insert last single linked list
void insertLast(string data2[3]){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
	newNode = new Buku();
	newNode->judul = data2[0];
	newNode->pengarang = data2[1];
	newNode->tempat_terbit = data2[2];
	newNode->next = head;
	tail->next = newNode;
	tail = newNode;
	}
}

//insert after single linked list
void insertAfter(string data[3], int posisi){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
		if(posisi == 1){
			cout<<"Posisi satu Bukan posisi tengah"<<endl;
		}else{
			newNode = new Buku();
			newNode->judul = data[0];
			newNode->pengarang = data[1];
			newNode->tempat_terbit = data[2];
			
			//transversing
			int nomor =1;
			cur = head;
			while(nomor < posisi -1){
				cur = cur->next;
				nomor++;
			}
			
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}
}

//delete first
void deleteFirst(){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
	del = head;
	head = head->next;
	tail->next = head;
	delete del;
	}
}

//delete last
void deleteLast(){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
	del = tail;
	cur = head;
	
	while(cur->next != tail){
		cur = cur->next;
	}
	
	tail = cur;
	tail->next = head;
	
	delete del;
	}
}

//delete after
void deleteAfter(int posisi){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
		//transversing
		int nomor = 1;
		cur = head;
		while(nomor < posisi -1){
		cur = cur->next;
		nomor++;
		}
	
		del = cur->next;
		cur->next = del->next;
		delete del;
		
	}
}

//print single linked list
void printCircular(){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
	cout<<"--Data Buku---"<<endl;
	cur = head;
	while(cur-> next!= head){
		cout<<"Judul Buku : "<<cur->judul<<endl;
		cout<<"Pengarang Buku : "<<cur->pengarang<<endl;
		cout<<"Tempat Terbit Buku : "<<cur->tempat_terbit<<endl;
		
		cur = cur->next;
	}
	cout<<"Judul Buku : "<<cur->judul<<endl;
	cout<<"Pengarang Buku : "<<cur->pengarang<<endl;
	cout<<"Tempat Terbit Buku : "<<cur->tempat_terbit<<endl;
	}
}
//searching (sequential)
void searchNode(Buku **head, int id){
    int currentID = 1;
    Buku *cur = *head;
    while (cur->next != 0 && currentID != id){
        cur = cur->next;
        currentID++;
    }
    cout << cur->judul << " ditemukan pada data ke " << currentID;
}

int main(){
	
	string dataBaru[3] = {"Matematika","Ahmad Sutan", "Jakarta"};
	createCircularSingleLinkedList(dataBaru);
	printCircular();
	cout<<"\n\n"<<endl;
	
	string data[3] = {"Bahasa Indonesia", "Susi Agustian", "Bandung"};
	insertFirst(data);
	printCircular();
	cout<<"\n\n"<<endl;
	
	string data2[3] = {"Sejarah", "Dian Anwar", "Batam"};
	insertLast(data2);
	printCircular();
	cout<<"\n\n"<<endl;
	
	string data3[3] = {"Kebumian", "Ratna Harto", "Yogyakarta"};
	insertAfter(data3, 5);
	printCircular();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printCircular();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printCircular();
	cout<<"\n\n"<<endl;
	
	deleteAfter(6);
	printCircular();
	cout<<"\n\n"<<endl;
	
	cout << "\nSearching judul : Kebumian" << endl;  
	searchNode(&head, 2);
	
	return 0;

}
