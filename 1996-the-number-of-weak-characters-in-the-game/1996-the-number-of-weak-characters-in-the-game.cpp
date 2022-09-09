class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    int maxAttack = 0;
    for (const auto& p : properties) {
      maxAttack = max(maxAttack, p[0]);
    }
    
    vector<int> maxDefenses (maxAttack + 2);
    for (const auto& p : properties) {
      int attack = p[0];
      int defense = p[1];
      maxDefenses[attack] = max(maxDefenses[attack], defense);
    }
    
    for (int i = maxDefenses.size() - 2; i >= 0; i--) {
      maxDefenses[i] = max(maxDefenses[i], maxDefenses[i+1]);
    }
    
    int weak = 0;
    for (const auto& p : properties) {
      int attack = p[0];
      int defense = p[1];
      if (maxDefenses[attack + 1] > defense)
        weak++;
    }
    
    return weak;
  }
};