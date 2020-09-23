#Returns First occurrance of the number in Array
def first_occurrance(a, num):
    i, j = 0, len(a)-1
    while i < j:
        mid= (i + j)//2
        if a[mid] < num:
            i = mid + 1
        else:
            j = mid
    return i if a[i] == num else -1

#Returns last occurrance of the number in Array
def last_occurrance(a, num):
    i, j = 0, len(a)-1
    while i <= j:
        mid = i + (j - i)//2
        # print(i,j, mid)
        if a[mid] <= num:
            i = mid + 1
        elif a[mid] > num:
            j = mid - 1
    return j if a[j] == num else -1

#Returns Number of occurrances of the number in Array
def number_of_occurrances(a, num):
    return (last_occurrance(a,num) - first_occurrance(a,num) + 1) if first_occurrance(a, num) != -1 else -1



def main():
    a = [1,2,2,2,3,3,3,3,3,3,3,4,4,5,6,7,8,8,9]
    num = 1
    
    print("First Occurrance of {} is: {}".format(num,first_occurrance(a, num)))
    print("Last Occurrance of {} is: {}".format(num, last_occurrance(a, num)))
    print("Number of Occurrance of {} is: {}".format(num, number_of_occurrances(a,num)))

if __name__ == '__main__':
     main()
