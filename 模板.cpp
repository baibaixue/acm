string Huffman::Decoding(string code){//выТы 
	node* temp=root;
	string text;
	for(int i=0;i<code.length();i++){
		char c=code[i];
		if(temp->lchild!=NULL&&temp->rchild!=NULL){
			if(c=='1'){
				temp=temp->rchild;
			}else if(c=='0'){
				temp=temp->lchild;
			}
			if(temp->lchild==NULL||temp->rchild==NULL){
				text+=temp->data;
				temp=root;
			}
		}
	}
	return text;
} 
