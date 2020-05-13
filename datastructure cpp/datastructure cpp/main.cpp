//
//  main.cpp
//  datastructure cpp
//
//  Created by Sureshkumar SP on 5/5/20.
//  Copyright © 2020 Sureshkumar SP. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char x = ' ';
    std::cin>>x;
    std::string text="You have pressed the key ";
    text+=x;
    text+="\n";
    std::cout<<text;
  return 0;
}
