// find peak
// bs dec
// bs inc
search
{
    int peak = find(arr);
    int idx = bsinc(arr, target, 0, peak);
    if (idx != -1)
        retun idx;
    else
        return bsdec(arr, target, peak + 1, n - 1);
}