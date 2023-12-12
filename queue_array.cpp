#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

class queue{

    private:
    int head;
    int tail;
    int array[5];

    public:
    queue(){

        this->head = -1;
        this->tail = -1;
    }

    bool is_empty(){

        if(this->head== -1 && this->tail == -1){

            return true;

        }else{return false;}
        
        
    }

    bool is_full(){

        int size = sizeof(array)/sizeof(array[0]);
        if(this->tail == size - 1){

            return true;

        }else{return false;}

    }

    void enqueue(int _data){

        if(this->is_full()){return;}
        if(this->is_empty()){

            this->head = this->tail = 0;

        }else{

            this->tail++;

        }

        this->array[tail] = _data;

    }


    int dequeue(){
        
        if(is_empty())
        {
        return -1;
        }else{

            int current_head = this->head;
            this->head++;
            return  array[current_head];
            
        }

       

    }   

    void size(){

        cout << "Queue size: " <<tail - head + 1<<endl;

    }

};

/*
int main(){

    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.size();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.size();
    
    return 0;

}*/