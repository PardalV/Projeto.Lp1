Funcionalidades:
Um sistema de gerenciamento de clínica/psicologo
- Podemos cadastrar pacientes, psicologos e rede de apoio do paciente
- Podendo cadastrar também a clínica e também cada sala presenta nela
- Na aba do paciente podemos anexar laudos e prontuarios (Apenas um laudo por paciente que pode ser mudado) (Prontuario também é só um que é sempre atualizado)
- O laudo precisa ter: Qual a condição, marcação no DSM, Médico que deu o laudo e o CRM. // Deve ter também uma função que printa todas essas infos de forma ordenada
- Prontuario deve ter: O string com o desenvolvimento das informações // Devemos também implementar um construtor que receba (Data da secção e desenvolvimento do dia) // Devemos ter uma função que printa o desenvolvimento inteiro junto com o nome do psicologo e seu CRP
- Em cada paciente devemos ter: Nome e id, que já vem da classe pai, devemos ter um prontuario e um laudo, devemos ter um pessoa de rede de apoio

- Para o polimorfismo vamos fazer uma função polimorfica de pessoa que expoe dados do paciente, do psicologo ou da rede de apoio
