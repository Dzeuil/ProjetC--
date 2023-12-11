// stack.hpp
#include <iostream>
#include <vector>

class Stack {
    private:
        std::vector<int> stack_vector;
        int taille;
    
    public:
        Stack(int taille) :taille(taille){
            stack_vector = std::vector<int>(taille);
            stack_vector.shrink_to_fit();
        }

        bool isEmpty() {
            if(taille == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        
        void push(int data) {
            stack_vector.insert(stack_vector.begin() + taille, data);
            taille ++;
        }

        int pop() {
            if(isEmpty()) {
                throw std::runtime_error("Stack is empty. Cannot pop an element.");
            }

            int popped_data = stack_vector[taille-1];
            stack_vector.erase(stack_vector.begin() + taille-1);
            taille --;

            return popped_data;
        }

        void print() {
            for(int i=0; i<taille; i++) {
                std::cout << stack_vector[i];
                std::cout << " ";
            }
        }

        int size() {
            return taille;
        }
};