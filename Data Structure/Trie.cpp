class Trie {
public:
    struct Node {
        Node* ar[12];
        bool endmark;
        Node() {
            endmark=false;
            for (int i=0; i<12; i++) ar[i]=NULL;
        }
    } ;
    Node* root;

    Trie() {
        root=new Node();
    }
    void Insert(const vii& s) {
        Node* cur=root;

        for (int i=1; i<=b; i++) {
            int ascii=s[i];
            if (cur->ar[ascii]==NULL) cur->ar[ascii]=new Node();
            cur=cur->ar[ascii];
        }
        cur->endmark=true;
    }
    int Search(const vii& s) {
        Node* cur=root;
        int ans = 0;
        for (int i=1; i<=b; i++) {
            int ascii=s[i];
            if (cur->ar[ascii]==NULL) return ans;
            ans++;
            cur=cur->ar[ascii];
        }
        return ans;
    }
    void Del(Node* cur)
    {
        for (int i=0; i<12; i++) {
            if (cur->ar[i]!=NULL) Del(cur->ar[i]);
        }
        delete(cur);
    }
    void Delete() {
        Del(root);
    }
};