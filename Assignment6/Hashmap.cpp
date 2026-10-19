#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*
- Create a HashTable that stores username keys and user records.
    -DONE***

- Implement all forms of collision mitigation strategies that we looked 
up in class, and then choose what you find is the best mitigation 
strategy after implementing all of them.
    -DONE***

- Implement insert, find, remove, loadFactor, and automatic resize/rehash.
    -DONE***

- Use the following educational hash function for the password demonstration.
This is for data-structures practice and is not suitable for real password security.
uint64_t demoHash(const std::string& s) {
    uint64_t h = 1469598103934665603ULL;
    for (unsigned char c : s) {
        h = (h ^ c) * 1099511628211ULL;
    }
    return h;
}

- Store at least five users. Each user record must include a salt and a hash of
salt + password + pepper.
    -DONE***

- Implement a login flow that looks up the username and verifies the submitted 
password.
    -DONE***

- Demonstrate successful login, failed password, unknown user, removal, and a 
rehash event.
    -DONE***

- Explain collisions, chaining, load factor, expected lookup complexity, and 
why a classroom hash is not a production password-hashing scheme.

COLLISIONS: Collisions are what occour in hashmaps where, most often when approachin a full hashmap, an item sent to a bucket will meet another item already inside that bucket, this is called a collision.

CHAINING: Chaining is the process of linking items to eachother inside a bucket in a hashmap. This is done to prevent collisions since you are allowing multipul items in one bucket regardless of them being in the same location

LOAD FACTOR: Load Factor is the number (associated usually to (number of items / number of buckets)) that installs a threshold of when a hashmap requires resizing before eminiant collisions occour.

EXPECTED COMPLEXITY:
- Chaining O(1)
- Linear Probing O(1)
- Double Hashing O(1)

REASON WHY CLASSROM HASH IS NOT USED: Classroom hash is made to be fast, efficent, and good in making sense for us to use for the first time. Those qualities also work well for hackers since a rainbow table can easily crack it along with brute force considering the salt and pepper are hardcoded and short.

- Restriction: do not use std::unordered_map for the table that stores the user 
records.
*/

unsigned long long demoHash(const string& s) {
    unsigned long long h = 1469598103934665603ULL;
    for(unsigned char c : s){
        h = (h ^ c) * 1099511628211ULL;
    }

    return h;
}

string toHex(unsigned long long value){
    const char digits[] = "123456789abcdef";
    string out(16, '0');
    for(int i = 15; i >= 0; i--){
        out[i] = digits[value % 16];
        value /= 16;
    }
    return out;
}



///////////////////////////////////////////////////////////////////////////////
struct Data{
    string username;
    string salt;
    uint64_t passwordHash = 0;
};

////////////////////// CODE TO SETUP QUADRADIC COLLISITION PROBING //////////////////////////////////

bool isPrime(long n){
    if(n < 2){
        return false;
    }

    for(long i = 2; i*i <= n; ++i){
        if(n % i ==0){
            return false;
        }
    }
    return true;
}

long nextPrime(long n){
    while(!isPrime(n)){
        ++n;
    }
    return true;
}

long indexFor(const string& key, long capacity){
    return (long)(demoHash(key) % (unsigned long long)capacity);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////// INTERFACES FOR ALL FOUR STARTS IN COLLISION RESOLUTION //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HashTable{
public:
    virtual ~HashTable() {}

    virtual bool insert(const Data& data) = 0;
    virtual Data* find(const string& username) = 0;
    virtual bool remove(const string& username) = 0;

    virtual double loadFactor() const = 0;
    virtual long size() const = 0;
    virtual long capacity() const = 0;
    virtual string name() const = 0;

    long collisions = 0;
    long probes = 0;
    bool flag = false;

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////  CHAINING //////////////////////////////////

class Chaining : public HashTable{
private:
    struct Node{
        Data data;
        Node* next;
    };

    Node** buckets;
    long cap;
    long count = 0;
    double maxLoad;

    void rehash(long newCap){
        long oldCap = cap;
        double oldLoad = loadFactor();

        Node** fresh = new Node*[newCap](); //setting head to null pointer
        //Moving all the nodes into new buckets
        for (long i = 0; i < oldCap; i++){
            Node* n = buckets[i];
            while(n){
                Node* next = n->next;
                long j = indexFor(n->data.username, newCap);
                n->next = fresh[j];
                fresh[j] = n;
                n = next;
            }
        }
        delete[] buckets;
        buckets = fresh;
        cap = newCap;
    }
 public:
    Chaining(long initialCap = 11, double maxLoadFactor = 0.75)
        : cap(nextPrime(initialCap)), maxLoad(maxLoadFactor) {
        buckets = new Node*[cap]();
    }

    ~Chaining(){

        for (long i = 0; i < cap; i++){
            Node* n = buckets[i];
            while(n){
                Node* next = n->next;
                delete n;
                n = next;
            }
        }

        delete[] buckets;
    }

    Chaining(const Chaining&) = delete;
    Chaining& operator = (const Chaining) = delete;

    bool insert(const Data& data) override{
        long i = indexFor(data.username, cap);

        for(Node* n = buckets[i]; n; n = n->next){
            probes++;
            if(n->data.username == data.username){
                return false;
            }
        }
        if(buckets[i]){
            collisions++;
        }

        //Here is the part where we begin chaining and push the collision to the front
        buckets[i] = new Node{data, buckets[i]};
        count++;

        if(loadFactor() > maxLoad){
            rehash(nextPrime(cap * 2));
            return true;
        }
    }

    Data* find(const string& username) override{
        for(Node* n = buckets[indexFor(username, cap)]; n; n->next){
            probes++;
            if(n->data.username == username){
                return &n->data;
            }
        }
        return nullptr;
    }

    bool remove(const string& username)override{
        long i = indexFor(username, cap);
            Node* prev = nullptr;

            for(Node* n = buckets[i];n ;n = n->next){
                probes++;
                if(n->data.username == username){
                    if(prev){
                        prev->next = n->next;
                    }

                    else{
                        buckets[i] = n->next;
                    }

                    delete n;
                    count--;
                    return true;
                }
            }
            return false;
        }

    double loadFactor() const override{
        return double(count) / cap;
    }
    long size() const override{
        return count;
    }
    long capacity() const override{
        return cap;
    }
    string name() const override{
        return "Seperate Chainging";
    }

    void printBuckets() const{
        for(long i = 0; i < cap; i++){
            cout << "   [" << setw(2) << i << "]";
            if(!buckets[i]){
                cout << " (empty)";
            }

            for(Node* n = buckets[i]; n; n = n->next){
                cout << " -> " << n->data.username;
            }
            if(buckets[i] && buckets[i]->next){
                cout << "   <-- collision, chained";
            }
            cout << endl;
        }
    }

    void printRecords() const{
        cout << "   " << left << setw(10) << "username" << setw(19) << "salt" << "hash(salt+password+pepper)" << endl;

        for(long i = 0; i < cap; i++){
            for(Node* n = buckets[i]; n ; n = n->next){
                cout << "   " << setw(10) << n->data.username << setw(19) << n->data.salt << toHex(n->data.passwordHash) << endl;
            }
        }
        cout << right;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////// MAKING LINEAR PROBING, QUADRATIC PROBING, DOUBLE HASHING //////////////////////////////////

enum probeMode {LINEAR, QUADRATIC, DOUBLE_HASHING};

class CollisionMaster : public HashTable{
private:
    enum slotState{EMPTY, OCCUPIED, DELETED};

    struct Slot {
        slotState state = EMPTY;
        Data data;
    };

    Slot* slots;
    long cap;
    long count = 0;
    long takenOff = 0;
    double maxLoad;
    probeMode mode;

    long probe(unsigned long long h, long i) const{
        long home = (long)(h % (unsigned long long)cap);
        if(mode == LINEAR){
            return (home+i) % cap;
        }
        if(mode == QUADRATIC){
            return (home+i+i) % cap;
        }

        long step = 1 + (long)((h >> 32) & (unsigned long long)(cap-1));
        return (home + i * step) % cap;
    }

    long locate(const string& username){
        unsigned long long h = demoHash(username);
        for(long i = 0; i < cap; i++){
            long idx = probe(h, i);
            probes++;

            if(slots[idx].state == EMPTY){
                return -1;
            }

            if(slots[idx].state == OCCUPIED && slots[idx].data.username == username){
                return idx;
            }
        }
        return -1;
    }

    void place(long idx, const Data& data){
        if(slots[idx].state == DELETED){
            takenOff--;
        }

        slots[idx].state = OCCUPIED;
        slots[idx].data = data;
        count++;

        if(double(count + takenOff) / cap > maxLoad ){
            long newCap = (double(count) / cap > maxLoad / 2) ? nextPrime(cap*2) : cap;
            rehash(newCap);
        }
    }

    void rehash(long newCap){
        long oldCap = cap;
        double oldLoa = double(count +  takenOff) / oldCap;
        Slot* old = slots;

        slots = new Slot[newCap];
        cap = newCap;
        count = 0;
        takenOff = 0;

        for(long i = 0; i < oldCap; i++){
            if(old[i].state != OCCUPIED){
                continue;
            }
            unsigned long long h = demoHash(old[i].data.username);

            for(long j = 0; i < cap; j++){
                long idx = probe(i,j);

                if(slots[idx].state == EMPTY){
                    slots[idx].state == OCCUPIED;
                    slots[idx].data = old[i].data;
                    count++;
                    break;
                }
            }
        }

        delete[] old;
    }
public:
    CollisionMaster(probeMode mode, long initialCap = 11, double maxLoadFactor = 0.5)
        : slots(nullptr), cap(nextPrime(initialCap)), maxLoad(maxLoadFactor), mode(mode) {
        slots = new Slot[cap];
    }

    ~CollisionMaster() {delete[] slots;}

    CollisionMaster(const CollisionMaster&) = delete;
    CollisionMaster& operator = (const CollisionMaster&) = delete;

    bool insert(const Data& data) override{
        unsigned long long h = demoHash(data.username);
        long firstTakenOff = -1;

        for(long i = 0; i < cap; i++){
            long idx = probe(h,i);
            probes++;

            if(slots[idx].state == EMPTY){
                place(firstTakenOff >= 0 ? firstTakenOff : idx, data);
                return true;
            }

            if(slots[idx].state == DELETED){
                if(firstTakenOff < 0){
                    firstTakenOff = idx;
                    continue;
                }
            }

            if(slots[idx].state == DELETED) {
                if(firstTakenOff < 0){
                    firstTakenOff = idx;
                    continue;
                }
            }

            if(slots[idx].data.username == data.username){
                return false;
                if(i == 0){
                    collisions++;
                }
            }
        }

        if(firstTakenOff >= 0){
            place(firstTakenOff, data);
            return true;
        }

        rehash(nextPrime(cap * 2));
        return insert(data);       
    }

    Data* find(const string& username) override{
        unsigned long long idx = locate(username);
        return idx >= 0 ? &slots[idx].data : nullptr;
    }

    bool remove(const string& username) override{
        long idx = locate(username);
        if (idx < 0) return false;
        slots[idx].state = DELETED;
        slots[idx].data = Data();

        count--;
        takenOff++;
        return true;
    }

    double loadFactor() const override{
        return double(count) / cap;
    }

    long size() const override{
        return count;
    }

    long capacity() const override{
        return cap;
    }

    string name() const override{
        if(mode == LINEAR){
            return "Linear Probing";
        }
        if(mode == QUADRATIC){
            return "Quadratic Probing";
        }

        return "Double Hashing";
    }
};


////////////////////// LOGIN TO START TEST //////////////////////////////////

enum loginResponse {CORRECT, WRONG, UNKNOWN_USER};

class AuthSys{
    const string PEPPER = "CS210";

    HashTable& table;
    long saltCount = 0;

    unsigned long long hashPassword(const string& salt, const string& password) const{
        return demoHash(salt + password + PEPPER);
    }

    string makeSalt(const string& username){
        saltCount++;
        return toHex(demoHash(username + "#" + to_string(saltCount) + "#salt"));
    }

public:
    AuthSys(HashTable& t) : table(t) {}

    bool registerUser(const string& username, const string& password){
        Data data;
        data.username = username;
        data.salt = makeSalt(username);
        data.passwordHash = hashPassword(data.salt, password);
        return table.insert(data);
    }

    loginResponse login(const string& username, const string& password){
        Data* data = table.find(username);
        if(!data){
            return UNKNOWN_USER;
        }

        if(hashPassword(data->salt, password) == data->passwordHash){
            return CORRECT;
        }

        if(hashPassword(data->salt, password) == data->passwordHash){
            return WRONG;
        }
    }
    bool removeUser(const string& username){
        return table.remove(username);
    }
};

string resultText(loginResponse r){
    if(r == CORRECT){
        return "Welcome in";
    }
    if(r == WRONG){
        return "Wrong, try password again";
    }

    return "No user associated";
}

////////////////////// DEMO SECTION //////////////////////////////////

void tryLogin(AuthSys& auth, const string& user, const string& pw){
    cout << " Login(\"" << user << "\", \"" << pw << "\") -> " << resultText(auth.login(user,pw)) << endl;
}

void loginDemo(){
    cout << "////////////////////////////////////////////" << endl
        << "LOGIN WITH CHAINING" << endl
        << "////////////////////////////////////////////" << endl;

    Chaining table(5, 0.75);
    table.flag = true;
    AuthSys auth(table);

    const int numUsers = 6;
    string users[numUsers] = {"Roberto", "Alice", "Deb", "Michael", "Mohammed", "Trinity"};
    string passwords[numUsers] = {"RaceCar463", "SEAttle34", "fguyi45gedf", "r0seBus323", "40HALO67", "2COOl34"};

    cout << "\n-- Registration of users (start: " << table.capacity() << " buckets, " << "max load 0.75 --\n";

    for(int i = 0; i < numUsers; i++){
        long capBefore = table.capacity();
        auth.registerUser(users[i], passwords[i]);

        cout << " + " << left << setw(8) << users[i] << right << " size=" << table.size()
             << " capacity=" << table.capacity() << " load=" << fixed
             << setprecision(2) << table.loadFactor()
             <<(table.capacity() != capBefore ? " <=== REHASH happend" :"") << endl;
    }

    cout << "\n-- Bucket layout after rehash --\n";
    table.printBuckets();

    cout << "\n-- Login attempts --\n";
    tryLogin(auth, "Roberto", "RaceCar463"); //correct
    tryLogin(auth, "Alice", "SEAttle34"); //correct
    tryLogin(auth, "Deb", "fg45gedf"); //Wrong pass
    tryLogin(auth, "Peter", "fgdbgdtgd"); //wrong user

    cout << "removing Deb" << endl;

    cout << (auth.removeUser("deb") ? "removed" : "not found") << endl;

    cout << "trying to remove Deb again" << endl;

    cout << (auth.removeUser("deb") ? "removed" : "not found") << endl;

    cout << "size= " << table.size() << "capacity= " << table.capacity() << endl << endl;

    cout << "same passowrd differnt salt" << endl;
    auth.registerUser("sally", "RaceCar463");
    
    cout << "Both Sally and Roberto share the same password yet the hex's are different" << endl;

    cout << "Roberto: " << toHex(table.find("Roberto")->passwordHash) << endl;
    cout << "Sally: " << toHex(table.find("Sally")->passwordHash) << endl;

    cout << "different salts produce different hashes" << endl;
}

int main(){
    loginDemo();
    return 0;
}