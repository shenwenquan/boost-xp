//
// Created by ice on 2017/5/7.
//

#ifndef BOOST_XP_USER_H
#define BOOST_XP_USER_H


class User {
public:
    User():state(1){
    }
    int getState(){
        return state;
    }
    void setState(int state){
        this->state=state;
    }
private:
    int state;

};


#endif //BOOST_XP_USER_H
