#include "InfNum.h"
#include "InfNumUtil.h"
#include "ArgumentManager.h"
#include <fstream>

struct node {
    std::string val;
    struct node * next;
};

int readFileToList(std::string filename, struct node * head){
    struct node * temp = head;
    fstream file;
    file.open(filename);
    int length = 0;
    if(file.is_open()){
        std::string str;
        while(getline(file, str)){
            temp->val = str;
            temp->next = new struct node;
            temp = temp->next;
            length++;
        }
        file.close();
    }
    return length;
}

void deleteLinkedList(struct node * head){
    struct node * temp = head;
    while(head != NULL){
        temp = head->next;
        delete(head);
        head = temp;
    }
}

InfNum * parseInputToArray(struct stats * myStats){
    struct node * head = new struct node;
    myStats->numElements = readFileToList(myStats->filename, head);
    InfNum * arr = (InfNum *)calloc(sizeof(InfNum), myStats->numElements);

    struct node * temp = head;
    for(int i = 0; i < myStats->numElements; i++){
        arr[i] = InfNum(temp->val, myStats->digPerNode);
        temp = temp->next;
    }
    deleteLinkedList(head);
    return arr;
}

int main(int argc, char ** argv){
    ArgumentManager am(argc, argv);

    struct stats * myStats = new struct stats;

    myStats->filename = am.get("input");
    myStats->algorithm = am.get("algorithm");
    myStats->output = am.get("output");
    myStats->digPerNode = am.get("digitsPerNode")[0] - '0';
  
    InfNum * arr = parseInputToArray(myStats);
    
    sortingCaller(arr, myStats);

    delete(arr); 
    //need to pass the struct and array to a function that will sort based on
    //algorithm

    
    return 0;
}
