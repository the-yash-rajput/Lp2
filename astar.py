# astar

class Node:
    def __init__(self,data,level,fval):
        self.data=data
        self.level=level
        self.fval=fval
    def generate_child(self):
        x,y=self.find(self.data,'_')
        children=[]
        val_list=[[x,y-1],[x,y+1],[x+1,y],[x-1,y]]
        for i in val_list:
            child=self.shuffle(self.data,x,y,i[0],i[1])
            if(child is not None):
                child=Node(child,self.level+1,0)
                children.append(child)
        return children
    def shuffle(self,puz,x1,y1,x2,y2):
        if(x2>=0 and x2< len(self.data) and y2>=0 and y2< len(self.data)):
            temp_puz=self.copy(puz)
            temp=temp_puz[x2][y2]
            temp_puz[x2][y2]=temp_puz[x1][y1]
            temp_puz[x1][y1]=temp
            return temp_puz
        else:
            return None
    def copy(self,puz):
        temp=[]
        for i in puz:
            t=[]
            for j in i:
                t.append(j)
            temp.append(t)
        return temp
    def find(self,puz,x):
        for i in range(len(puz)):
            for j in range(len(puz)):
                if(puz[i][j]=='_'):
                    return i,j
class Puzzle:
    def __init__(self,size):
        self.n=size
        self.open=[]
        self.close=[]
    def accept(self):
        puz=[]
        for i in range(self.n):
            t=input().split()
            puz.append(t)
        return puz
    def f(self,start,goal):
        return self.h(start.data,goal)+start.level
    def h(self,start,goal):
        c=0
        for i in range(self.n):
            for j in range(self.n):
                if(start[i][j]!=goal[i][j] and start[i][j]!='_'):
                    c+=1
        return c
    def process(self):
        print("Initital State")
        start=self.accept()
        print("Goal State")
        goal=self.accept()
        start=Node(start,0,0)
        start.fval=self.f(start,goal)

        self.open.append(start)
        print("\n\n")
        while(1):
            cur=self.open[0]
            print("")
            print("  | ")
            print("  | ")
            print(" \\\'/ \n")
            for i in cur.data:
                for j in i:
                    print(j,end=" ")
                print(" ")
            if(self.h(cur.data,goal)==0):
                break
            for i in cur.generate_child():
                i.fval=self.f(i,goal)
                self.open.append(i)
            self.close.append(cur)
            del self.open[0]

            self.open.sort(key=lambda x:x.fval,reverse=False)


puz=Puzzle(3)
puz.process()