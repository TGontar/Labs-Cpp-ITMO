#include "subset.h"
#include "menu.h"

#include <iostream>


using std::cout;
using std::cin;
using std::endl;

//default constructor
Menu::Menu() {
    currentSubset = nullptr;
}

//create a subset with a maximum number of elements given
Subset *Menu::createSubset() {
    int mx;
    cout << "Write the maximum number of elements in a subset: " << endl;
    cin >> mx;
    while (mx <= 0) {
        cout << "The maximum number of elements should be positive" << endl;
        cin >> mx;
    }

    Subset *temp = new Subset(mx);

    int cnt;
    cout << "Enter the number of elements to push in new subset " << endl;
    cin >> cnt;
    while (cnt <= 0 or cnt > mx) {
        cout << "The number shouldn't be negative and should be less then maxsize" << endl;
        cin >> cnt;
    }

    cout << "Enter the integers you want to add into subset: " << endl;
    for (int i = 0; i < cnt; i++) {
        int val;
        cin >> val;
        temp->pushElem(val);
    }

    return temp;
}

//print the subset
void Menu::printSubset(Subset *s) {
    if (s == nullptr) {
        cout << "The subset doesn't exist" << endl;
    } else {
        s->printSubset();
    }
}

//add the element
void Menu::addElement() {
    int val;
    cout << "Enter a value you want to add: " << endl;
    cin >> val;
    if (currentSubset == nullptr or !currentSubset->pushElem(val)) {
        cout << "Cannot add a value: the subset isn't created or it's overloaded or the element is already in subset"
             << endl;
    } else {
        cout << "Success" << endl;
    }
}

//pop the element
void Menu::popElement() {
    int val;
    cout << "Enter a value you want to pop: " << endl;
    cin >> val;
    if (currentSubset == nullptr or !currentSubset->popElem(val)) {
        cout << "Cannot pop a value: the subset isn't created or it's empty or the element isn't in subset" << endl;
    } else {
        cout << "Success" << endl;
    }
}

//check the element
void Menu::checkElement() {
    int val;
    cout << "Enter a value you want to check: " << endl;
    cin >> val;
    if (currentSubset->checkInSubset(val)) {
        cout << "The element " << val << " is in the subset" << endl;
    } else {
        cout << "The element " << val << " is not in the subset" << endl;
    }
}

//intersect two subsets: current and the new one
void Menu::intersectSubsets() {
    cout << "First, give a Subset to intersect with current." << endl;
    Subset *temp = createSubset();
    Subset *intersect = currentSubset->intersectSubset(*temp);
    cout << "The intersection of current subset and new subset:" << endl;
    printSubset(intersect);

    delete temp;
    delete intersect;
}

//unite two subsets: current and the new one
void Menu::uniteSubsets() {
    cout << "First, give a Subset to unite with current." << endl;
    Subset *temp = createSubset();
    Subset *unite = currentSubset->unionSubset(*temp);
    cout << "The union of current subset and new subset:" << endl;
    printSubset(unite);

    delete temp;
    delete unite;
}

//add all elements from new subset to current
void Menu::addFromAnother() {
    cout << "First, give a Subset, which will be added to current." << endl;
    Subset *temp = createSubset();
    currentSubset->addFromAnotherSubset(*temp);
    cout << "The result:" << endl;
    printSubset(currentSubset);

    delete temp;
}

//remove all elements of new subset from current
void Menu::rmFromAnother() {
    cout << "First, give a Subset, which will be removed from current." << endl;
    Subset *temp = createSubset();
    currentSubset->removeFromAnotherSubset(*temp);
    cout << "The result:" << endl;
    printSubset(currentSubset);

    delete temp;
}

//stop the program
void Menu::stopProgram() {
    cout << "Bye" << endl;
    delete currentSubset;
}

//interface
void Menu::menuInterface() {
    cout << "Hello, to continue please create a subset" << endl;
    currentSubset = createSubset();
    bool stop = false;
    while (!stop) {
        int choice = 0;

        cout << endl;
        cout << "Please, choose what to do with your subset" << endl;
        cout << "1. Check if the element n is in subset" << endl;
        cout << "2. Add element n to subset" << endl;
        cout << "3. Remove element n from the subset" << endl;
        cout << "4. Find the intersection of current subset with a new one" << endl;
        cout << "5. Find the union of current subset with a new one" << endl;
        cout << "6. Add all the elements from a new subset to the current one" << endl;
        cout << "7. Remove all the elements of a new subset from the current one" << endl;
        cout << "8. Print the current subset" << endl;
        cout << "9. End the program" << endl;

        cin >> choice;
        if (choice <= 0 or choice >= 10) {
            cout << "Insert a number between 1 and 9" << endl;
        } else if (choice == 1) {
            checkElement();
        } else if (choice == 2) {
            addElement();
        } else if (choice == 3) {
            popElement();
        } else if (choice == 4) {
            intersectSubsets();
        } else if (choice == 5) {
            uniteSubsets();
        } else if (choice == 6) {
            addFromAnother();
        } else if (choice == 7) {
            rmFromAnother();
        } else if (choice == 8) {
            printSubset(currentSubset);
        } else if (choice == 9) {
            stop = true;
        }
    }

    stopProgram();
}