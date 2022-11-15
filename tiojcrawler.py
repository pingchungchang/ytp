from bs4 import BeautifulSoup
import requests
import time


def get_problems(inp):
    re = requests.get(inp)
    soup = BeautifulSoup(re.text,"html.parser")
    soup = soup.find(class_='table table-condensed')
    soup = soup.find_all('a')
    # soup = soup.find_all(class_ = '')
    re = []
    for i in soup:
        k = i.attrs['class'][0]
        if k == 'text-success':
            re.append([i.text,1])
        else:
            re.append([i.text,0])
    # for i in soup:
    #     print(i.__class__)
    return re
def FindDiff():
    user1 = "https://tioj.ck.tp.edu.tw/users/"
    user2 = 'https://tioj.ck.tp.edu.tw/users/'
    user1 = user1+input('enter handle of first user:\n')
    user2 = user2+input('enter handle of second user:\n')
    arr1 = get_problems(user1)
    arr2 = get_problems(user2)
    anob = []
    bnoa = []
    for i in range(len(arr1)):
        if arr1[i][1] == 1 and arr2[i][1] == 0:
            anob.append(arr1[i][0])
        elif(arr1[i][1] == 0 and arr2[i][1] == 1):
            bnoa.append(arr1[i][0])
    print("first but not second:")
    for i in anob:
        print(i,end = ',')
    print()
def FindRate():
    arr = []
    for i in range(1,14):
        print(i)
        now_page = 'https://tioj.ck.tp.edu.tw/problems?page='+str(i)
        re = requests.get(now_page)
        soup = BeautifulSoup(re.text,'html.parser')
        soup = soup.find(class_ = 'table-hover')
        soup = soup.find('tbody').find_all('tr')
        for i in soup:
            tmp = i.find_all('td')
            # print(tmp[1].text,tmp[2].text,tmp[4].text)
            if tmp[4].text.split(' ')[0] == 'NaN%':
                continue
            arr.append([tmp[1].text,tmp[2].text,float(tmp[4].text.split(' ')[0][:-1])])
            arr[-1][0] = arr[-1][0].replace('\n',' ')
            arr[-1][1] = arr[-1][1].replace('\n',' ')
            # print(tmp[4].text.split(' '))
        time.sleep(0.3)
    arr = sorted(arr,key=lambda x:x[2])
    for i in arr:
        print(i)
        print(' ')
def Solve():
    s = input("choose mode(enter f or d to compare two users, other characters to find AC rate for tioj)\n")
    if s[0] == 'd' or s[0] == 'f':
        FindDiff()
    else:
        FindRate()
while True:
    Solve()