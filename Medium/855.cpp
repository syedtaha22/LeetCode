#include <set>

class ExamRoom {
private:
    int n;
    std::set<int> seats;
public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        int maxDist = *seats.begin();
        int seatToChoose = 0;
        int prev = -1;

        for (int seat : seats) {
            if (prev == -1) {
                prev = seat;
                continue;
            }
            int dist = (seat - prev) / 2;
            if (dist > maxDist) {
                maxDist = dist;
                seatToChoose = prev + dist;
            }
            prev = seat;
        }
        if ((n - 1 - *seats.rbegin()) > maxDist) {
            seatToChoose = n - 1;
        }
        seats.insert(seatToChoose);
        return seatToChoose;
    }

    void leave(int p) { seats.erase(p); }
};