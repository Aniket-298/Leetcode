class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveAlice_month=stoi(arriveAlice.substr(0,2));
        int leaveAlice_month=stoi(leaveAlice.substr(0,2));
        
        int arriveAlice_day=stoi(arriveAlice.substr(3,2));
        int leaveAlice_day=stoi(leaveAlice.substr(3,2));


        int arriveBob_month=stoi(arriveBob.substr(0,2));
        int leaveBob_month=stoi(leaveBob.substr(0,2));
        
        int arriveBob_day=stoi(arriveBob.substr(3,2));
        int leaveBob_day=stoi(leaveBob.substr(3,2));

        vector<int>vec={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

       if(leaveAlice_month<arriveBob_month || leaveBob_month<arriveAlice_month) return 0;
    //    if(arriveAlice_month==arriveBob_month){
    //     if(max(arriveAlice_day, arriveBob_day) >  min(leaveAlice_day, leaveBob_day)) return 0;
    //     // else  return max(0,(min(leaveBob_day,leaveAlice_day))-max(arriveAlice_day,arriveBob_day))+1;
    //    }
       


        int ans=0;

        for(int i=max(arriveAlice_month,arriveBob_month);i<=min(leaveAlice_month,leaveBob_month);i++){
            // ans+=(vec[i-1]-max(arriveBob_day,arriveAlice_day)+vec[i-1]-min(leaveAlice_day,leaveBob_day));

            // if(i==max(arriveAlice_month,arriveBob_month) && i==min(leaveAlice_month,leaveBob_month)){
            //     // ans+=min(leaveAlice_day,leaveBob_day)-max(arriveBob_day,arriveAlice_day)+1;
            //     if(i==arriveAlice_month) ans+=min(leaveAlice_day,leaveBob_day)-arriveAlice_day+1;
            //     else if(i==arriveBob_month) ans+=min(leaveAlice_day,leaveBob_day)-arriveBob_day+1;
            //     else ans+=min(leaveAlice_day,leaveBob_day)-max(arriveBob_day,arriveAlice_day)+1;
            // }
            if(i == max(arriveAlice_month, arriveBob_month) &&
                i == min(leaveAlice_month, leaveBob_month)) {

                int startDay, endDay;

                if(arriveAlice_month == i && arriveBob_month == i) startDay = max(arriveAlice_day, arriveBob_day);
                else if(arriveAlice_month == i) startDay = arriveAlice_day;
                else startDay = arriveBob_day;

                if(leaveAlice_month == i && leaveBob_month == i) endDay = min(leaveAlice_day, leaveBob_day);
                else if(leaveAlice_month == i) endDay = leaveAlice_day;
                else endDay = leaveBob_day;
                ans += max(0, endDay - startDay + 1);
            }
            else if(i==max(arriveAlice_month,arriveBob_month)){
                if(i == arriveAlice_month && i == arriveBob_month) ans += vec[i-1] - max(arriveAlice_day, arriveBob_day) + 1;
                else if(i==arriveAlice_month)  ans+=vec[i-1]-arriveAlice_day+1;
                else ans+=vec[i-1]-arriveBob_day+1;
            }
            else if(i==min(leaveAlice_month,leaveBob_month)){
                if(i==leaveAlice_month && i==leaveBob_month) ans+=min(leaveAlice_day,leaveBob_day);
                else if(i==leaveBob_month) ans+=leaveBob_day;
                else ans+=leaveAlice_day;
            }
            else{
                ans+=vec[i-1];
            }
        }
        return ans;
        
    }
};