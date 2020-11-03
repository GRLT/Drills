#include "../std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const char result = '=';
const char square_root = '@';
const char pows = 'p';

const string declkey = "let";
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string quitkey = "quit";

//Func. Declaration
double expression();
double primary();
double term();
double declaration();
double statement();
double calc_sqrt();
double calc_pow();

// Vars
class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var)
{
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s)
{
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
	return -1;
}

void set_value(string s, double d)
{
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
	error("set: undefined variable", s);
}


// Token
class Token {
public:
	char kind;
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};


// Token_stream
class Token_stream {
public:
	Token_stream();
	void putback(Token t);
	Token get();
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch)
	{
		case print:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
			return Token(ch);
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback (ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default: 
    	{
    		if (isalpha(ch))
    		{
    			string s;
    			s += ch;
    			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
    			cin.putback(ch);
    			if (s == declkey) return Token{let};
				else if (s == sqrtkey) return Token{square_root};
				else if (s == powkey) return Token{pows};
				else if (s == quitkey) return Token(quit);
    			else if (is_declared(s))
    				return Token(number, get_value(s));
    			return Token{name,s};
    		}
    		error("Bad token");
    	}
    	return 0;
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}

Token_stream ts;

void clean_up_mess()
{
	ts.ignore(print);
}

void calc()
{
	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main() 
try {

	define_name("k", 1000);

	calc();

	return 0;

} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}

//Functions rules
double calc_pow(){
		double i = term();
		double d = expression();
		cout << "asd1: " <<i <<endl;
		cout << "asd2: " << d << endl;
        return pow(d, i);
}


double calc_sqrt(){
	char ch;
	if (cin.get(ch) && ch != '(') error("'(' expected");
	cin.putback(ch);
	double d = expression();
	if (d < 0) error("sqrt:negative value");
	return sqrt(d);
}

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		case square_root:
			return calc_sqrt();
		case pows:
			return calc_pow();
		default:
			error("primary expected");
	}
	return -1;
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) error("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error("%: divide by zero");
				left = fmod (left, d);
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true)
	{
		switch(t.kind)
		{
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch(t.kind)
	{
		case quit:
			return 0;
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}