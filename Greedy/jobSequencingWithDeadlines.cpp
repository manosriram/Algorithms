#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;

// Checks if First Job's Profit is greater than the Second Job's Profit or not.
bool greaterINT(const pair<int, int> p1, const pair<int, int> p2) {
    return p1.first> p2.first;
}

// Calculate Profit.
int calculateProfit(vector<pair<int, int> > job) {
    // Start with Zero Profit.
    int profit = 0;
    // Sort the Job in non-decreasing order of profits.
    sort(job.begin(), job.end(), greaterINT);
   
    // Get Maxumum number of slots.
    int noOfSlots = max_element(job.begin(), job.end(), [](const pair<int, int> p1, const pair<int, int> p2) {return p1.second < p2.second;})->second;
    
    // Create an  boolean array which indicates if the slot is occupied or not.
    bool slot[noOfSlots+1];
    // Start with none of the slots occupied by equaling them to false.
    memset(slot, false, noOfSlots+1);
    
    // Visit each Job.
    for (int t=1;t<=job.size();++t) {
        // 'in' is the 't-1st' Job.
        pair<int, int> in = job[t - 1];

        /*
            cu -> 'in'th Job's Deadline.
            val -> 'in'th Job's Profit.
        */

        int cu = in.second;
        int val = in.first;

        // while deadline is greater then 0..
        while (cu > 0) {
            // If the slot is occuped, check for next non-occupied index to the left.
            if (slot[cu] == true)
                --cu;
            // If found, break.
            else
                break;
        }
        // If the deadline is greater than zero, set that slot as occupied and add the job's weight to the profit.
        if (cu > 0) {
            slot[cu] = true;
            profit += val;
        }
    }
    // return the final profit.
    return profit;
}

int main() {
    vector< pair<int, int> > job; // <profits, deadlines> 
    
    job.push_back(make_pair(20, 2));
    job.push_back(make_pair(15, 2));
    job.push_back(make_pair(10, 1));
    job.push_back(make_pair(5, 3));
    job.push_back(make_pair(1, 3));

    int profit = calculateProfit(job); 
    
    cout << profit << endl;
}  
