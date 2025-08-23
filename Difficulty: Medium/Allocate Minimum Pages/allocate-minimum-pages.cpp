class Solution {
  public:
    int canAllocate(int maxPage, const vector<int>& arr, int k) {
    int currStud = 1, pages = 0;
    for (int pagesInBook : arr) {
        if (pagesInBook > maxPage) return false; // 💡 key fix for optimized range
        if (pages + pagesInBook <= maxPage)
            pages += pagesInBook;
        else {
            currStud++;
            pages = pagesInBook;
        }
    }
    return currStud <= k;
}

int findPages(vector<int>& arr, int k) {
    if (arr.size() < k) return -1;
    int totalPage = accumulate(arr.begin(), arr.end(), 0);
    int low = totalPage / k;

    while (low <= totalPage) {
        int mid = low + (totalPage - low) / 2;
        if (canAllocate(mid, arr, k))
            totalPage = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
};