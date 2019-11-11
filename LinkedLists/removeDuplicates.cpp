void removeDuplicates (SinglyLinkedListNode * head)
{
	HashSet<int> set = new HashSet<int>();
	SinglyLinkedListNode* prev = nulltpr;

	while( head != nullptr)
	{
		if(set.contains(head->data))
		{
			prev->next = head->next;
		}
		else
		{
			set.add(head->data)
			previous = head;
		}
		head = head->next;
	}
}