//
// Created by ahmed-essam100 on 03/11/18.
//

#ifndef LAB2_OS2_MATRIX_INIT_H
#define LAB2_OS2_MATRIX_INIT_H

typedef enum variation{By_Row, By_Element}variation;


void Matrix_init();
void *get_call_back(int variation);
void *Multiply_row(void* thread_id);
void *Multiply_element(void* thread_id);
#endif //LAB2_OS2_MATRIX_INIT_H
