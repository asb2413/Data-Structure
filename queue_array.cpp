#include <iostream>
using namespace std;


template<typename type>
class Queue{
    private:
    type* entries;
    int head;
    int tail;
    int init_Size = 6 ;
    int length;
    int entries_count;

    public:
    
    Queue(){

        this->entries = new type[init_Size];
        this->length = init_Size;
        this->entries_count = 0; 
        this->head = -1;
        this->tail = -1;

    }

    //resize function when queue is full

    void resize(){

        if(this->entries_count == this->length - 1){

            int new_size = this->length + init_Size;
            type *new_entries = new type[new_size];
            for(int i = 0; i < this->length; i++){

                	new_entries[i] = this->entries[i];

            } 

            delete[] entries;
            this->entries = new_entries;
            
            this->length = new_size;

        }

    }

    //queue empty check
    bool is_empty(){

        if(this->head == -1 && this->tail == -1){ return true;}
        return false;
    }

    //queue enqueue
    void enqueue(type _data){

        resize();

        if(is_empty()){

            this->head = this->tail = 0;

        }else{

            this->tail++;

        }

        this->entries[tail] = _data;
        this->entries_count++;

    }

//queue dequeue
    type dequeue(){

        /*if (((this->head == -1 && this->tail == -1) || (this->entries[this->tail] == type() || this->entries[this->tail] == nullptr)) &&
        (this->entries[this->head] == type() || this->entries[this->head] == nullptr))*/
        if(this->head == -1 && this->tail == -1 || this->entries[this->head]== type() && this->entries[this->head]== type()){
            
            return "queue is empty";
            
            }else{

            type current_data = this->entries[this->head];
            this->entries[this->head] = type();
            this->head++;
            this->entries_count--;
            return  current_data;

            }
        

    }

    // queue peak

    type peak(){

        if(this->head == -1 && this->tail == -1){
            
            return "queue is empty";
            
            }else{

            return  this->entries[this->head];

            }

    }

    int entries_in_queue(){

        return this->entries_count;

    }

    int queue_size(){

        return this->length;

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