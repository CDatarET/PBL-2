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
    cout << "Username: " << username;
    cout << "\nMobile Number: " << mobileNum << "\n\n";
}

void MobileUser::heapSort(){

}

void mergeSort(MobileUser db[], int low, int high, int ){

}

void qSortRec(MobileUser db[], int p, int r){
    if(p < r){
        int q = partition(db, p, r);
        qSortRec(db, p, q - 1);
        qSortRec(db, q + 1, r);
    }
}

int partition(MobileUser db[], int p, int r){
    int x = db[r].mobileNum;
}

int main(){
    cout << "Hello World\n";
    int n;
    cout << "Enter number of users: ";
    cin >> n;
    MobileUser db[n];

    for(int i = 0; i < n; i++) db[i].accept();
    for(int i = 0; i < n; i++) db[i].display();

    char yn = 'y';
    while(yn == 'y'){
        cout << "Enter Heap Sort, Merge Sort, or Quick sort. H/M/Q:";
        char hmq;
        cin >> hmq;

        switch(hmq){
            case 'h':
                break;
            
            case 'm':
                break;
            
            case 'q':

        }
    }

    return(0);
}