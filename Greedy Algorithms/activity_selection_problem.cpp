#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

// Comparator function to sort activities by their finish times
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

vector<Activity> selectActivities(vector<Activity>& activities) {
    // Sort activities by their finish times
    sort(activities.begin(), activities.end(), compare);

    vector<Activity> selected;
    int lastFinishTime = 0;

    for (const auto& activity : activities) {
        if (activity.start >= lastFinishTime) {
            selected.push_back(activity);
            lastFinishTime = activity.finish;
        }
    }

    return selected;
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    vector<Activity> result = selectActivities(activities);

    cout << "Selected activities:\n";
    for (const auto& activity : result) {
        cout << "Start: " << activity.start << ", Finish: " << activity.finish << "\n";
    }
    return 0;
}