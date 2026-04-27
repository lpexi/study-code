#include <iostream>
#include <string>

class Note
{
private:
    std::string* text;
    
public:
    Note(std::string text_in)
    {
        text = new std::string;
        *text = text_in;
    }
    Note(const Note &other_note)
    {
        text = new std::string;
        *text = *(other_note.text);
    }
    ~Note()
    {
        delete text;
        text = nullptr;
        std::cout << "deleted text and released memory" << std::endl;
    }
    void display();
};

void Note::display()
{
    std::cout << *text << std::endl;
}

int main()
{
    Note note_1("meine Nachricht");
    Note note_2("meine Nachricht");

    note_1.display();
    note_2.display();

    return 0;
}
