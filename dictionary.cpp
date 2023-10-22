#include <iostream>
using namespace std;





template<typename T>
class Dictionary {
private:
    class KeyValuePair {
    
        private:
        T key;
        T value;
    public:
        
        
        KeyValuePair(T key, T value) {
            this->key = key;
            this->value = value;
        }

        KeyValuePair(){}

        T getKey() { return key; }
        T getValue() { return value; }
        void setValue(T value) {
            this->value = value;
        }
    };

    KeyValuePair* entries;
    int length;
    int initSize;
    int entriesCount;

public:
    Dictionary() {
        this->initSize = 3;
        this->entries = new KeyValuePair[this->initSize];
        this->length = this->initSize;
        this->entriesCount = 0;
    }

    // Other methods...

    void resize() {
        if (this->entriesCount < this->length - 1) {
            return;
        } else {
            int newSize = this->length + this->initSize;
            KeyValuePair* newEntries = new KeyValuePair[newSize];

            for (int i = 0; i < size; i++) {
                newEntries[i] = this->entries[i];
            }

            delete[] this->entries;
            this->entries = newEntries;
            this->length = newSize;
        }
    }
    //set
    void set(T key , T value){

        for(int i = 0; i < this->length;i++){

            if(!this->entries[i].getKey().empty() && this->entries[i].getKey() == key ){

                this->entries[i].setValue(value);
                return;
            }


        }

        KeyValuePair newPair(key,value);
        this->entries[this->entriesCount] = newPair;
        this->entriesCount++;

    }
    //get
     T get(T key){

        for(int i = 0; i < this->length;i++){

            if(!this->entries[i].getKey().empty() && this->entries[i].getKey() == key ){

                return this->entries[i].getValue();
            }
        }
        return "not found";

     }
    //remove

    bool Remove(T key){

        for(int i = 0; i < this->length;i++){

            if(!this->entries[i].getKey().empty() && this->entries[i].getKey() == key ){

                this->entries[i] = this->entries[this->entriesCount-1];
                this->entries[this->entriesCount-1] = KeyValuePair();
                this->entriesCount--;
                return true;
            }


    }
    return false;
    }

    int size() { return entriesCount; }

    void print(){

        for(int i = 0; i < this->length;i++){

            cout<< "key: "<< this->entries[i].getKey()<< " value: " << this->entries[i].getValue()<< endl;

        }

    }

    
};


/*
int main()
{
        Dictionary<string> dictionary;
        dictionary.set("1","abdullah");
        dictionary.set("2","samir");
        dictionary.set("3","saleh");
        dictionary.print();
       
        return 0;
}*/