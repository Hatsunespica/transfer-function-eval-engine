#ifndef EVAL_ENGINE_UTILS_H
#define EVAL_ENGINE_UTILS_H

void tf_getTop(APInt* arg, APInt* result){
    APInt tmp(arg[0].getBitWidth(), 0);
    result[0] = tmp;
    result[1] = tmp;
}

void tf_meet(APInt* arg0, APInt* arg1, APInt* result){
    result[0] = arg0[0] | arg1[0];
    result[1] = arg0[1] | arg1[1];
}

APInt smin(APInt arg0, APInt arg1){
    return arg0.sle(arg1)?arg0:arg1;
}

APInt umin(APInt arg0, APInt arg1){
    return arg0.ule(arg1)?arg0:arg1;
}

APInt smax(APInt arg0, APInt arg1){
    return arg0.sge(arg1)?arg0:arg1;
}

APInt umax(APInt arg0, APInt arg1){
    return arg0.uge(arg1)?arg0:arg1;
}

#endif
