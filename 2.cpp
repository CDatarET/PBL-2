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

void merge(MobileUser db[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;

    MobileUser temp[high - low + 1];
    while (i <= mid && j <= high){
        if (db[i].username > db[j].username){
            temp[k++] = db[i++];
        } else {
            temp[k++] = db[j++];
        }
    }

    while (i <= mid){
        temp[k++] = db[i++];
    }

    while (j <= high){
        temp[k++] = db[j++];
    }

    for (int x = 0; x < k; x++){
        db[low + x] = temp[x];
    }
}

void mergeSort(MobileUser db[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergeSort(db, low, mid);
        mergeSort(db, mid + 1, high);
        merge(db, low, mid, high);
    }
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
        cout << "Enter Merge Sort or Quick sort. M/Q:";
        char mq;
        cin >> mq;

        switch(mq){            
            case 'M':
                mergeSort(db, 0, n - 1);
                cout << "Username   Mobile Number\n";
                for(int i = 0; i < n; i++){
                    db[i].display();
                }
                break;
            
            case 'Q':
                qSortRec(db, 0, n - 1);
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
