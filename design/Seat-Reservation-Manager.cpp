// LEETCODE -- 1845.Seat Reservation Manager

#include <iostream>
#include <queue>
using namespace std;

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i = 1; i<=n; i++) {
            pq.push(i);
        }
    }
    
    int reserve() {
        int seat = pq.top(); 
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);  
    }
};

int main() {
    int n = 5; // Assuming there are 5 seats initially
    SeatManager* obj = new SeatManager(n);

    // Reserve a seat
    int reservedSeat = obj->reserve();
    cout << "Reserved seat: " << reservedSeat << endl;

    // Unreserve the seat
    int seatToUnreserve = reservedSeat;
    obj->unreserve(seatToUnreserve);
    cout << "Seat " << seatToUnreserve << " unreserved." << endl;

    // Reserve another seat
    int reservedSeat2 = obj->reserve();
    cout << "Reserved seat: " << reservedSeat2 << endl;

    // Don't forget to free the memory allocated for the SeatManager object
    delete obj;

    return 0;
}
