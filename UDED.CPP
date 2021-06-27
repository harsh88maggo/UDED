#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<bits/stdc++.h>
#include<vector>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main1()
{
    // CAESAR CIPHER

	int i,ch,key;
	char t[50],n;
	cout<<"Enter the text\n";
	cin.ignore();
	cin.getline(t,50);
	cout<<"Enter key\n";
	cin>>key;
	for(i=0;t[i]!='\0';++i)
	{
		n=t[i];
		if(n>='a'&&n<='z')
		{
			n+=key;
			if(n>'z')
			{
				n=n-'z'+'a'-1;
			}
			t[i]=n;
		}
		else if(n>='A'&&n<='Z')
		{
			n+=key;
			if(n>'Z')
			{
				n=n-'Z'+'A'-1;
			}
			t[i]=n;
		}
	}
	cout<<"Text has been encrypted\nEnter any character to continue\n";
	char a;
	cin>>a;

	cout<<"Encrypted text : "<<t<<endl;
	for(i=0;t[i]!='\0';++i)
	{
		n=t[i];
		if(n>='a'&&n<='z')
		{
			n-=key;
			if(n<'a')
			{
				n=n+'z'-'a'+1;
			}
			t[i]=n;
		}
		else if(n>='A'&&n<='Z')
		{
			n-=key;
			if(n<'A')
			{
				n=n+'Z'-'A'+1;
			}
			t[i]=n;
		}
	}
	cout<<"To see the decrypted text press y/Y\n";
	char b;
	cin>>b;
	cout<<"Decrypted text : "<<t<<endl;

	return 0;
}

int main2()
{
	// MODIFIED CAESAR CIPHER

	int i,l,ch,key;
	char t[50],n;
	cout<<"Enter the text\n";
	cin.ignore();
	cin.getline(t,50);
	cout<<"Enter key\n";
	cin>>key;
	l=strlen(t);
	for(i=0;t[i]!='\0';++i)
	{
		n=t[i];
		if(i%2==0)
		{
		if(n>='a'&&n<='z')
		{
			n+=key+1;
			if(n>'z')
			{
				n=n-'z'+'a'-1;
			}
			t[i]=n;
		}
		else if(n>='A'&&n<='Z')
		{
			n+=key+1;
			if(n>'Z')
			{
				n=n-'Z'+'A'-1;
			}
			t[i]=n;
		}
		}
		else
		{
			if(n>='a'&&n<='z')
		{
			n+=key-1;
			if(n>'z')
			{
				n=n-'z'+'a'-1;
			}
			t[i]=n;
		}
		else if(n>='A'&&n<='Z')
		{
			n+=key-1;
			if(n>'Z')
			{
				n=n-'Z'+'A'-1;
			}
			t[i]=n;
		}
		}
	}
	cout<<"Text has been encrypted\nEnter any character to continue\n";
	char a;
	cin>>a;

	cout<<"Encrypted text : "<<t<<endl;
	for(i=0;t[i]!='\0';++i)
	{
		n=t[i];
		if(i%2==0)
		{
		if(n>='a'&&n<='z')
		{
			n-=key+1;
			if(n<'a')
			{
				n=n+'z'-'a'+1;
			}
			t[i]=n;
		}
		else if(n>='A'&&n<='Z')
		{
			n-=key+1;
			if(n<'A')
			{
				n=n+'Z'-'A'+1;
			}
			t[i]=n;
		}
		}
		else
		{
		if(n>='a'&&n<='z')
		{
			n-=key-1;
			if(n<'a')
			{
				n=n+'z'-'a'+1;
			}
			t[i]=n;
		}
		else if(n>='A'&&n<='Z')
		{
			n-=key-1;
			if(n<'A')
			{
				n=n+'Z'-'A'+1;
			}
			t[i]=n;
		}
		}
	}
	cout<<"To see the decrypted text press y/Y\n";
	char b;
	cin>>b;
	cout<<"Decrypted text : "<<t<<endl;

	return 0;
}



// Vigenere Cipher


// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text
string generateKey(string str, string key)
{
	int x = str.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{
		// converting in range 0-25
		int x = (str[i] + key[i]) %26;

		// convert into alphabets(ASCII)
		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		// converting in range 0-25
		int x = (cipher_text[i] - key[i] + 26) %26;

		// convert into alphabets(ASCII)
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

// Driver program to test the above function
int main3()
{
	string str;
	string keyword;
    cout<<"MESSAGE : ";
    cin.ignore();
    getline(cin,str);
    cout<<"Key : ";
    getline(cin,keyword);
	string key = generateKey(str, keyword);
	string cipher_text = cipherText(str, key);

	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Original/Decrypted Text : "
		<< originalText(cipher_text, key)<<endl<<endl;

	return 0;
}

// Playfair Cipher


void get_pos(char, int&, int&);
void same_row(int, vector<char>&, int, int);
void same_column(int, vector<char>&, int, int);
void diff_col_row(int, int, vector<char>&, int, int);
void encode(vector<char>, int);
void get_input(vector<char>&);
void convert_string(vector<char>&, vector<char>&);

const char encoder[5][5]={{'A','B','C','D','E'},
                      {'F','G','H','I','K'},
                      {'L','M','N','O','P'},
                      {'Q','R','S','T','U'},
                      {'V','W','X','Y','Z'}};

void get_pos(char p, int& r, int& c)
{
    if (p < 'J')
    {
        r = (p - 65) / 5;
        c = (p - 65) % 5;
    }
    else if (p > 'J')
    {
        r = (p - 66) / 5;
        c = (p - 66) % 5;
    }
    return;
}

void same_row(int r, vector<char>& code, int c1, int c2)
{
    code.push_back(encoder[r][(c1 + 1) % 5]);
    code.push_back(encoder[r][(c2 + 1) % 5]);
    return;
}

void same_column(int c, vector<char>& code, int r1, int r2)
{
    code.push_back(encoder[(r1 + 1) % 5][c]);
    code.push_back(encoder[(r2 + 1) % 5][c]);
    return;
}

void diff_col_row(int r1, int c1, vector<char>& code, int r2, int c2)
{
    code.push_back(encoder[r1][c2]);
    code.push_back(encoder[r2][c1]);
    return;
}

void same_rowd(int r, vector<char>& code, int c1, int c2)
{
    code.push_back(encoder[r][(c1 + 4) % 5]);
    code.push_back(encoder[r][(c2 + 4) % 5]);
    return;
}

void same_columnd(int c, vector<char>& code, int r1, int r2)
{
    code.push_back(encoder[(r1 + 4) % 5][c]);
    code.push_back(encoder[(r2 + 4) % 5][c]);
    return;
}

void diff_col_rowd(int r1, int c1, vector<char>& code, int r2, int c2)
{
    code.push_back(encoder[r1][c2]);
    code.push_back(encoder[r2][c1]);
    return;
}

void decode(vector<char> msgx, int len)
{
    vector<char> code;
    int i = 0, j = 0;
    int r1, c1, r2, c2;
    while (i < len)
    {
        get_pos(msgx[i], r1, c1);
        i++;
        get_pos(msgx[i], r2, c2);
        if (r1 == r2)
        {
            same_rowd(r1, code, c1, c2);
        }
        else if (c1 == c2)
        {
            same_columnd(c1, code, r1, r2);
        }
        else
        {
            diff_col_rowd(r1, c1, code, r2, c2);
        }
        i++;
    }
    cout<<"\nMESSAGE: ";
    for (j = 0;j < code.size();j++)
    {
        if (code[j] == 'X')
        continue;
        cout<<code[j];
    }
    cout<<endl<<endl;
    return;
}

void encode(string msgx, int len)
{
    vector<char> code;
    int i = 0, j = 0;
    int r1, c1, r2, c2;
    while (i < len)
    {
        get_pos(msgx[i], r1, c1);
        i++;
        get_pos(msgx[i], r2, c2);
        if (r1 == r2)
        {
            same_row(r1, code, c1, c2);
        }
        else if (c1 == c2)
        {
            same_column(c1, code, r1, r2);
        }
        else
        {
            diff_col_row(r1, c1, code, r2, c2);
        }
        i++;
    }
    cout<<"\nCODE: ";
    for (j = 0;j < code.size();j++)
    {
        cout<<code[j];
    }
    cout<<endl<<endl;
    cout<<"\n\nDecoded Message:- \n";
    decode(code,len);
    return;
}

/*void get_input(vector<char>& a)
{
    char c[50];
    int i=0;
    while (1)
    {
        cin.ignore();
        cin.getline(c,50);
        if (c[i] >= 97 && c[i] <= 122)
        c[i]-=32;
        if (c[i] == '\n')
            break;
        else if (c[i]==' ')
            continue;
        else if (c[i] == 'J')
        a.push_back('I');
        a.push_back(c[i]);
        i++;
    }
    return;
}
*/
void convert_string(string& msg, string& msgx)
{
    int i, j;
    i = j = 0;
    while (i < msg.size())
    {
        msgx.push_back(msg[i]);
        i++;
        if (i == msg.size())
        {
            msgx.push_back('X');
            break;
        }
        if (msg[i] == msgx[j])
        {
            msgx.push_back('X');
            j++;
        }
        else if(msg[i] != msgx[j])
        {
            j++;
            msgx.push_back(msg[i]);
            i+= 1;
        }
        j++;
    }
}

int main4()
{
    string msg;
    string msgx;
    int i, j;
    cout<<"Enter Message to Encrypt: ";
    //get_input(msg);
    string c;
    int a=0;
    while (1)
    {
        cin.ignore();
        getline(cin,c);
        if (c[a] >= 97 && c[a] <= 122)
        c[a]-=32;
        if (c[a] == '\n')
            break;
        else if (c[a]==' ')
            continue;
        else if (c[a] == 'J')
        msg.push_back('I');
        msg=c[a];
        a++;
    }
    convert_string(msg, msgx);
    int len = msgx.size();
    encode(msgx, len);

    return 0;
}

// RSA Algorithm


long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
int main5()
{
    cout << "\nENTER FIRST PRIME NUMBER\n";
    cin >> p;
    flag = prime(p);
    if (flag == 0)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    cout << "\nENTER ANOTHER PRIME NUMBER\n";
    cin >> q;
    flag = prime(q);
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT\n";
        exit(1);
    }
    cout << "\nENTER MESSAGE\n";
    fflush(stdin);
    cin >> msg;
    for (i = 0; msg[i] != '\0'; i++)
        m[i] = msg[i];
    n = p * q;
    t = (p - 1) * (q - 1);
    ce();
    /*cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
    for (i = 0; i < j - 1; i++)
        cout << e[i] << "\t" << d[i] << "\n";
    */encrypt();
    decrypt();
    return 0;
}
void ce()
{
    int k;
    k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}
long int cd(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}
void encrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nENCRYPTED MESSAGE:\n";
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);

    cout<<endl;
}
void decrypt()
{
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\nDECRYPTED MESSAGE:\n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);

    cout<<endl<<endl;
}


void getkeymatrix(int keysize, char key[100],int keymatrix[][100])
{
	int k=0;
	for(int i=0;i<keysize;i++)
	{
		for(int j=0;j<keysize;j++)
		{
			keymatrix[i][j]=(key[k])%65;
			k++;
		}
	}
}
void encrypt1(int ciphermatrix[][100],int keymatrix[][100],int message[][100],int keysize)
{
	int x,i,j;
	for(i=0;i<keysize;i++)
	{
		for(j=0;j<1;j++)
		{
			ciphermatrix[i][j]=0;
			for(x=0;x<keysize;x++)
			{
				ciphermatrix[i][j]+=keymatrix[i][x]*message[x][j];
			}
			ciphermatrix[i][j]=(ciphermatrix[i][j])%26;
		}
	}
}
void hillcipher()
{
	char msg[100],key[100],ciphertext[100],a,b;
	int i,keymatrix[100][100],keysize,message[100][100],ciphermatrix[100][100];
	cout<<"Enter the message (Should be less than 10 characters)\n";
	cin.ignore();
	cin.getline(msg,10);
	keysize=strlen(msg);
	cout<<"Enter the key\n";
	cin.getline(key,keysize*keysize);
	for(i=0;i<keysize;i++)
	{
		message[i][0]=(msg[i])%65;
	}
	getkeymatrix(keysize,key,keymatrix);
	encrypt1(ciphermatrix,keymatrix,message,keysize);
	for(i=0;i<keysize;i++)
	{
		ciphertext[i]+=ciphermatrix[i][0]+65;
	}
	cout<<"Enter any key to show encrypted text\n";
	cin>>b;
	cout<<"Encrypted text : "<<ciphertext<<endl;
	cout<<"Enter any key to show decrypted text\n";
	cin>>a;
	cout<<"Decrypted text : "<<msg<<endl;
}




int main()
{
	char choice;
	do
	{
	int x;

	cout<<"**********UDED(USER DEFINED ENCRYPTION DECRYPTION)**********"<<endl;
	cout<<endl;
	cout<<"Choose your preferred cryptography method:"<<endl;
	cout<<endl;
	cout<<"1.CAESAR CIPHER\n2.MODIFIED CAESAR CIPHER\n3.PLAYFAIR CIPHER\n4.RSA\n5.HILL CIPHER"<<endl;
	cin>>x;

	switch(x)
	{
		case 1:main1();
		       break;

		case 2:main2();
		       break;

		case 3:main4();
		       break;

		case 4:main5();
		       break;

        case 5:hillcipher();
               break;


		default:cout<<"Wrong Input!!!"<<endl;
			break;

	};

	cout<<"Do you wish to continue?(Y/N)"<<endl;
	cin>>choice;

	}while(choice=='y'||choice=='Y');

	return 0;
}
