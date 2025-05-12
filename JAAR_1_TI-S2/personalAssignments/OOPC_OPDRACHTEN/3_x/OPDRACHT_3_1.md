Opdracht OO3.1 Auto

Voor variabelen geeft auto aan dat het type van de variabele automatisch wordt afgeleid bij initialisatie.

Voer onderstaande opdracht uit door de code alleen te lézen. Gegeven de klasse definitions (zie onder).

    Geef aan wat de typen zijn van de variabelen a t/m i.

class course {
public:
    const std::vector<char> name;
};

class mark {
public:
    course& course;
    uint8_t number;
};

class student {
public:
    const std::string name;
    int number;
    std::vector<mark> marks;
};

class klas {
public:
    const std::array<char, 3> name;
    std::vector<student> students;
    klas() {
    }
};

...
klas v1a;
auto a = v1a;
auto b = a.name;
auto c = a.students[3];
auto d = c.name;
auto e = c.number;
auto f = c.marks[7];
auto g = f.course;
auto h = f.number;
auto i = g.name;
...

a = class klas
b = const std::array char die bestaat uit 3 chars
c = een student van de std::vector<student> uit de class klas
d = const std::string van de class student
e = int van de class student
f = std::vector<mark> van class student
g = is een course van de class course (volgens chatgpt course&, vragen hoezo)
h = uint8_t van de class mark
i = const std::vector<char> van de class course
