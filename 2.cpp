#include <iostream>
using namespace std;

class MobileUser{
    private:
        double billAmt;

    public:
        string username;
        long mobileNum;

        void accept();
        void display();
        void heapSort();
};

void MobileUser::accept(){
    cout << "Enter Username: ";
    cin >> username;
    
    cout << "Enter Mobile number: ";
    cin >> mobileNum;

    cout << "\n";
}

void MobileUser::display(){
    cout << username << "          " << mobileNum << "\n\n";
}

void heapSort(){

}

void mergeSort(MobileUser db[], int low, int high, int ){

}

void swap(MobileUser &a, MobileUser &b){
    MobileUser t = a;
    a = b;
    b = t;
}

int partition(MobileUser db[], int p, int r){
    int x = db[r].mobileNum;
    int i = p - 1;
    for(int j = p; j < r; j++){
        if (db[j].mobileNum <= x){
            i++;
            swap(db[i], db[j]);
        }
    }
    swap(db[i + 1], db[r]);
    return(i + 1);
}

void qSortRec(MobileUser db[], int p, int r){
    if(p < r){
        int q = partition(db, p, r);
        qSortRec(db, p, q - 1);
        qSortRec(db, q + 1, r);
    }
}

int main(){
    cout << "Hello World\n";
    int n;
    cout << "Enter number of users: ";
    cin >> n;
    MobileUser db[n];

    for(int i = 0; i < n; i++){
        db[i].accept();
    }

    cout << "Username   Mobile Number\n";
    for(int i = 0; i < n; i++){
        db[i].display();
    }

    char yn = 'y';
    while(yn == 'y'){
        cout << "Enter Heap Sort, Merge Sort, or Quick sort. H/M/Q:";
        char hmq;
        cin >> hmq;

        switch(hmq){
            case 'H':
                break;
            
            case 'M':
                break;
            
            case 'Q':
                qSortRec(db, 0, n);
                cout << "Username   Mobile Number\n";
                for(int i = 0; i < n; i++){
                    db[i].display();
                }

        }

        cout << "Again? y/n:";
        cin >> yn;
    }

    return(0);
}
