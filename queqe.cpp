
template<class T>
struct Node                             //////// Creamos la estructura nodo
{
  T data;
  Node<T> *next;                      /////////7  Dos miembros dato
  Node(T d):data(d),next(NULL){}
};

template <class T>
class Queqe                           ////////77  Creamos la clase cola
{
  Node<T> *head;                        ///////   Dos miembros dato
  Node<T> *tail;
public:
  Queqe():head(NULL),tail(NULL){}
  ~Queqe();
  void enqueqe(T );                     //////////  4 funciones miembro
  T dequeqe();
  bool is_empty();
  T view_next();
};
template<class T>
Queqe<T>::~Queqe()
{
  while(head){                    ////////  Recorremos y eliminamos secuencialmente
    Node<T> *temp=head;
    head=head->next;
    delete temp;
    cout<<"Nodo borrado.......\n";
  }
}

template<class T>
void Queqe<T>::enqueqe(T datoIngresado)
{
  if(!head){
    head=tail=new Node<T>(datoIngresado);
  }                                             /////7  Validamos si esta vacia la cola
  else{
    tail->next=new Node<T>(datoIngresado);
    tail=tail->next;                             /////////7 Solo movemos la cola
  }
}

template<class T>
T Queqe<T>::view_next()                   ////////7   Funcion para ver el siguiente elemento de la cola
{
  if(!head)
    return 0;     ///////////   La cola esta vacia
  return head->data;
}

template<class T>
T Queqe<T>::dequeqe()
{
  T retornable=view_next();
  if(!head)   ////////////7     La cola esta vacia retorna cero
    return retornable;              ///////7  Validamos si esta vacia la cola
  Node<T> *temp=head;
  head=head->next;                //////////  Recorremos la cabeza ,capturamos el dato , liberamos memoria y retornamos el valor
  delete temp;                  ///////////     en ese orden..........
  return retornable;
}
