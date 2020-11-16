class FreqStack {
    private:
        unordered_map<int,stack> Stacks;
        unordered_map<int,int> Freq;
        int Max;

    public:
        FreqStack() {
            Max=0;
        }

        void push(int x) {
            Freq[x]++;
            Stacks[Freq[x]].push(x);
            Max = max(Max,Freq[x]);
        }

        int pop() {
            int Ans = Stacks[Max].top();
            Stacks[Max].pop();
            Freq[Ans]--;

            if(Stacks[Max].empty()){
              Max--;
            }
                
            return Ans;
        }
};