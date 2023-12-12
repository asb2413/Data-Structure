#include <cstring>
#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

//this is hash class

class Hash{

    private:
    string input;
    int input_len;
    public:
    Hash(){};
    Hash(string input){

        this->input = input;
        this->input_len = input.length();

    }

    //here is the hash function FNV-1a
    //using int32_t cus thje function returne number of  32bit
    
   uint32_t FNV_1a_32bit(int hash_table_len){
        

        uint32_t off_set_basis = 2166136261;
        uint32_t Prime = 16777619;
        uint32_t hash = off_set_basis;
        
        //pointer to the array of char (the string) to make C-style so we can copy memory block 
        const char* data  = this->input.c_str();
        // creating array of 8bits = 1bytes
        uint8_t *bytes = new uint8_t[input_len];
        //copy the array of char (data) to bytes  array
        memcpy(bytes, data, input_len);
        
        //FNV logic
        for(int i = 0;i<input_len;i++){

            hash = hash ^ bytes[i];
            hash = hash * Prime;

        }
        
        hash = hash % hash_table_len;

        return static_cast<int>(hash);


    }

};

template<typename type>
class Hash_table{
    private:
    class Key_pair_value{
        private:
        string key;
        type value;
        public:
        
        Key_pair_value(){

            this->key = "";
            this->value = type();
        };
        Key_pair_value(string key, type value){

            this->key = key;
            this->value = value;

        }

        string get_key (){

            return this->key;

        }

        void set_value(type value){

            this->value = value;

        }

        type get_value(){

            return this->value;

        }

    };

    public:
    //hash table prop
    Key_pair_value* entries;
    int initSize = 3;
    int length;
    int entriesCount ;

//constructer
Hash_table(){

    this->entries = new Key_pair_value[this->initSize];
    this->length = initSize;
    this->entriesCount = 0;

};




// collesion handling method for set and get methods
int collesion(type key, int hash, string method_type){

    for(int i = 1; i <= this->length - 1; i++){
        int new_hash = (hash + i) % (this->length);
        if(method_type == "set" && (this->entries[new_hash].get_key().empty() || this->entries[new_hash].get_key() == key)){

            return new_hash;

        }else if(method_type == "get" && this->entries[new_hash].get_key() == key){

            return new_hash;

        }else{

            continue;

            }

   }

    return -1;

}

// add new key value to hash table
void add_to_hashTable(string key, type value){
        Hash new_hash(key);
        int hash = new_hash.FNV_1a_32bit(this->length); 
        if (!this->entries[hash].get_key().empty() && this->entries[hash].get_key() != key)
        {
            hash = collesion(key, hash, "set");
        }

        if (hash == -1)
        {

            throw runtime_error("invalid hashTable");
        }

        if (this->entries[hash].get_key().empty())
        {

            this->entries[hash] = Key_pair_value(key, value);
            this->entriesCount++;
        }
        else if (this->entries[hash].get_key() == key)
        {

            this->entries[hash].set_value(value);
        }
        else
        {
            throw runtime_error("invalid hashTable");
        }
}


//hash table add more and resize
void resize(){

    
    if(entriesCount == this->length-1){
    int new_size = this->length * 2;
    Key_pair_value* new_entries = new Key_pair_value[new_size];
    for(int i = 0; i<this->length; i++){

        new_entries[i] = this->entries[i] ;

    }
    delete[] this->entries;
    this->length = new_size;
    this->entries = new Key_pair_value[this->length];
    
    for(int i = 0; i<length; i++){

        if(new_entries[i].get_key().empty()){continue;}
        add_to_hashTable(new_entries[i].get_key(),new_entries[i].get_value());

    }
    
    }

}
void set(string key, type value){
    resize();
    add_to_hashTable(key, value);
}

Key_pair_value get(string key) {
    Hash hash(key);
    int index = hash.FNV_1a_32bit(this->length);
    
    if(!entries[index].get_key().empty() && entries[index].get_key() != key){
        index = collesion(key, index, "get");
    }
    if(index == -1){
        return Key_pair_value();
    }
    if(this->entries[index].get_key() == key){
        return this->entries[index];
    } else {
        return Key_pair_value();
    }  
}

void remove(string key){

    Hash hash(key);
    int index = hash.FNV_1a_32bit(this->length);
    
    if(!entries[index].get_key().empty() && entries[index].get_key() != key){
        index = collesion(key, index, "get");
    }

    if(index == -1){
        cout<< ""<<endl;
    }
    if(this->entries[index].get_key() == key){
         this->entries[index] = Key_pair_value();
    } else {
        cout<< ""<<endl;
    }  

}

int size(){return this->length;}
void print(){

    for(int i = 0; i <= this->length - 1; i++){

        cout<< "key: " << this->entries[i].get_key()<< " value: " << entries[i].get_value()<< endl;

    }

}
};



int main()
{

    

    //=================================
    
 Hash_table<string> hash_table;
    hash_table.set("a","abdullah");
    hash_table.set("b","samir");
    hash_table.set("c","saleh");
    
    hash_table.print();
    cout << "========================"<<endl;
    // get
    cout<< " key "<< hash_table.get("b").get_key()<< " value " << hash_table.get("b").get_value()<<endl;
    cout << "========================"<<endl;
    //remove and print
    hash_table.remove("a");
    hash_table.print();

    return 0;
}
