from bs4 import BeautifulSoup
import requests
import time


user = ''
solved = []
def GetProblems(inp):
    global nullresponse
    re = requests.get(inp)
    soup = BeautifulSoup(re.text,"html.parser")
    soup = soup.find(class_='table table-condensed')
    if soup == None:
        return 'fail'
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
    global user
    user1 = "https://tioj.ck.tp.edu.tw/users/"
    user2 = 'https://tioj.ck.tp.edu.tw/users/'
    user2 = user2+user
    user1 = user1+input('enter handle of another user:\n')
    arr1 = GetProblems(user1)
    arr2 = GetProblems(user2)
    if type(arr1) == type('hi') or type(arr2) == type('hi'):
        print('failed')
        return
    anob = []
    bnoa = []
    for i in range(len(arr1)):
        if arr1[i][1] == 1 and arr2[i][1] == 0:
            anob.append(arr1[i][0])
        elif(arr1[i][1] == 0 and arr2[i][1] == 1):
            bnoa.append(arr1[i][0])
    print("solved by rival:\n")
    for i in anob:
        print(i,end = ',')
    print()
def FindProblems():
    sort_type = input('enter sort type (a:ac rate,p:solve count)\n');
    arr = []
    for i in range(1,14):
        print('processing:'+str(i)+'/13')
        now_page = 'https://tioj.ck.tp.edu.tw/problems?page='+str(i)
        re = requests.get(now_page)
        soup = BeautifulSoup(re.text,'html.parser')
        soup = soup.find(class_ = 'table-hover')
        soup = soup.find('tbody').find_all('tr')
        for i in soup:
            tmp = i.find_all('td')
            # print(tmp[1].text,tmp[2].text,tmp[4].text)
            if tmp[1].text in solved:
                continue
            else:
                arr.append([tmp[1].text,tmp[2].text,float(tmp[4].find('a').text.split('/')[0])])
            arr[-1][0] = arr[-1][0].replace('\n',' ')
            arr[-1][1] = arr[-1][1].replace('\n',' ')
            # print(tmp[4].text.split(' '))
        # time.sleep(0.05)
    arr = sorted(arr,key=lambda x:x[2])
    for i in arr:
        print(i)
        print(' ')
def Solve():
    global user,solved
    s = input("choose mode(enter h for help)\n")
    if len(s) == 0:
        print('error\n')
    elif s[0] == 'd':
        FindDiff()
    elif s[0] == 'h':
        print('functions:\nd:compare with another user\np:print unsolved problems with specific order accending\nc:change user\ns:show solved ids')
    elif s[0] == 'p':
        FindProblems()
    elif s[0] == 'c':
        user = input('enter user id:\n')
        solved = GetProblems("https://tioj.ck.tp.edu.tw/users/"+user)
        while type(solved) == type('hi'):
            print('invalid user id')
            user = input('enter user id:\n')
            solved = GetProblems("https://tioj.ck.tp.edu.tw/users/"+user)
        er = []
        for i in solved:
            if i[1] == 0:
                er.append(i)
        for i in er:
            solved.remove(i)
        for i in range(len(solved)):
            solved[i].pop()
            solved[i] = str(solved[i][0])
    elif s[0] == 's':
        for i in solved:
            print(i)
if __name__ == '__main__':
    user = input('enter user id:\n')
    solved = GetProblems("https://tioj.ck.tp.edu.tw/users/"+user)
    while type(solved) == type('hi'):
        print('invalid user name')
        user = input('enter user id:\n')
        solved = GetProblems("https://tioj.ck.tp.edu.tw/users/"+user)
    er = []
    for i in solved:
        if i[1] == 0:
            er.append(i)
    for i in er:
        solved.remove(i)
    for i in range(len(solved)):
        solved[i].pop()
        solved[i] = str(solved[i][0])
    # print(solved)
    while True:
        Solve()