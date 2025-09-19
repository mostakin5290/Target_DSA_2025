class Spreadsheet {
    unordered_map <string,int> un;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        un[cell]=value;
    }
    
    void resetCell(string cell) {
        un[cell]=0;
    }

    int getCellValue(string token){
        if(un.find(token)!=un.end())
            return un[token];
            
        if(isalpha(token[0]))
            return 0;
        return stoi(token);
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        int plus = formula.find('+');
        string left = formula.substr(0,plus);
        string right = formula.substr(plus+1);

        return getCellValue(left) + getCellValue(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */