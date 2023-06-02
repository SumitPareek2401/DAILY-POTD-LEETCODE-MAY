class UndergroundSystem {
public:
    map<int, pair<int,string>>m;
    map<string, pair<int,int>>p;
    UndergroundSystem() {
        m.clear();
        p.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id] = {t,stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        string d = m[id].second + " " + stationName;
        auto &i = p[d];
        i.first += t - m[id].first;
        i.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + " " + endStation;
        return (double)p[route].first/p[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
