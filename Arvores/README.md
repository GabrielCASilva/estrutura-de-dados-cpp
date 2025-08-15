# Árvores

## Definição

Tipo Abstrato de dado que armazena dados de maneira hierárquica. Os elementos de uma árvore geralmente tem um pai e zero
ou mais filhos.

> O elemento no topo da árvore é chamado de **raiz**

## Definição formal

Uma árvore é representada por um conjunto de nós representados numa relação de pai e filho.

- Se a árvore não está vazia, ela tem um elemento especial, chamado raiz, que não tem pai.
- Cada nó da árvore, diferente da **raiz**, tem um nó pai em comum e todos os nós são filhos desse nó pai.

> Dois nós que tem o mesmo pai são **irmãos**.
>
> Nós que não tem filhos são nós **externos** ou **folhas**.
>
> Nós **internos** são aqueles que tem filhos.

## Exemplo

Um diretório de pastas em um sistema operacional é representado por uma árvore. Sua represetação é feita de várias
pastas aninhadas entre si. No UNIX, por exemplo, a raiz dessa árvore é chamada de ***root directory***. 

```
cursos
├── logica_de_programação
│   ├── típos_primitivos
│   └── lacos_de_repeticao
├── algoritmos
│   └── algoritmos_de_busca
│       └── busca_binaria
└── estrutura_de_dados
    ├── tabela_hash
    └── arvores
        └── arvore_binaria
```

No exemplo acima, `busca_binaria` é descendente de `algoritmos` e `estrutura_de_dados` é um antecessor de
`arvore_binaria`. Pode-se dizer também que, a partir do nó `algoritmos` existe um exemplo de uma subárvore na árvore
`cursos`.

> Uma subárvore é um recorte de um conjunto de nós em uma árvore.
> A árvore com a **raiz** no nó `algoritmos` é uma subárvore da árvore com sua **raiz** sendo o nó `cursos`.

## Árvore Ordenada

Uma árvore está ordenada quando os seus irmãos estão em uma ordem linear

```
livro
├── capitulo_um
│   ├── paragrafo_um_um
│   └── paragrafo_um_dois
├── capitulo_dois
│   ├── paragrafo_dois_um
│   └── paragrafo_dois_dois
└── capitulo_tres
    ├── paragrafo_tres_um
    └── paragrafo_tres_dois
```
